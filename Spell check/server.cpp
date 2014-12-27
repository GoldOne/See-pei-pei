#include <fstream>
#include <pthread.h>
#include "wrappers.h"
using namespace std;

const int LISTENQUEUENUM=3;
const char* DICTFILENAME="/usr/dict/words";
const char* TMPFILEPREFIX="tmp";
const int WORDLENGTH=64;
const int LINELENGTH=512;

int NumUniqueChars(const char* word1,const char* word2)
{
	int result=0;
	for(int i=0;word1[i];i++)
		if(strchr(word2,word1[i])==0)
	    		result++;
	for(int i=0;word2[i];i++)
		if(strchr(word1,word2[i])==0)
	    		result++;
	return result;
}

int WordCmp(char* word1,char* word2)
{
	if(!strcmp(word1,word2))
		return 0;
	if(word1[0]!=word2[0])
		return 100;
	float aveWordLen=(strlen(word1)+strlen(word2))/2.0;
	return int(NumUniqueChars(word1,word2)/aveWordLen*100);
}

int findSimilar(ifstream& dict,char* word,char* right_word)
{
	int similarNum=100;
	int i,ret;
	char wordbuf[WORDLENGTH];

	// Convert all uppercase letters to lowercase
	for(i=0;word[i];i++)
		word[i]=tolower(word[i]);

	// Remove leading or tailing punctuation characters
	for(i=0;word[i]&&!isalpha(word[i]);i++);
		if(word[i]=='\0')   // no alphabetic characters
			return 0;
	if(i)
		strcpy(word,word+i);
	for(i=strlen(word);i>=0&&!isalpha(word[i]);i--);
		word[i+1]='\0';

	// read dictionary file to check the similarNum
	dict.clear();
	dict.seekg(0,ios_base::beg);
	dict>>wordbuf;
	while(!dict.eof()&&similarNum)
	{
		ret=WordCmp(word,wordbuf);
		if(ret<similarNum)
		{
			strcpy(right_word,wordbuf);
			similarNum=ret;
		}
		dict>>wordbuf;
	}

	if(similarNum==100)
		strcpy(right_word,"no suggestion");

	return similarNum;
}

void exit_thread(int cfd,void* ret)
{
	close(cfd);
	pthread_exit(ret);
}

extern "C" void* thread(void* arg)
{
	int cfd=*(int*)arg;
	int tmp_fd;
	char tmp_file[20];
	ifstream dict,tmp;
	uint32_t filesize,sum=0;
	char buffer[BUFFERLENGTH];
	int ret=0;
	char wordbuf[WORDLENGTH],right_wordbuf[WORDLENGTH];
	char linebuf[LINELENGTH];
	int lineno=0;
	char *p;

	// open temporary file for writing
	sprintf(tmp_file,"%s_%d",TMPFILEPREFIX,cfd);
	tmp_fd=open(tmp_file,O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	if(tmp_fd<0)
	{
		perror("Create temporary file");
		exit_thread(cfd, NULL);
	}

	// open dictionary file for reading
	dict.open(DICTFILENAME);
	if(!dict.good())
	{
		cerr<<"Fail to open the dictionary file "<<DICTFILENAME<<endl;
		exit_thread(cfd,NULL);
	}

	// read the file size from the client
	if(read(cfd,&filesize,sizeof(filesize))<0)
	{
		perror("Read file size");
		exit_thread(cfd,NULL);
	}
	filesize=ntohl(filesize);

	// read the content of the document and write to the temporary file
	do
	{
		ret=read(cfd,buffer,sizeof(buffer));
		write(tmp_fd,buffer,ret);
		sum+=ret;
	}
	while(sum<filesize&&ret>=0);
	if(ret<0)
	{
		perror("Read document");
		exit_thread(cfd,NULL);
	}

	// Open the temporary file again for reading
	close(tmp_fd);
	tmp.open(tmp_file);

	// read the temporary file and check every word
	tmp.getline(linebuf,sizeof(linebuf),'\n');
	while(!tmp.eof())
	{
		lineno++;
		p=strtok(linebuf, " ");
		while(p)
		{
			strcpy(wordbuf,p);
			if(findSimilar(dict,wordbuf,right_wordbuf))
			{
				wrapString(buffer,lineno, wordbuf,right_wordbuf);
				write(cfd, buffer,sizeof(buffer));
			}
			p=strtok(NULL, " ");
		}
		tmp.getline(linebuf, sizeof(linebuf), '\n');
	}

		// send the result to client
	if(write(cfd,FINISHSIGN,strlen(FINISHSIGN)+1)<0)
		perror("Send result");
	// Close the client socket fd and files
	dict.close();
	tmp.close();

	// Remove the temporary file
	remove(tmp_file);

	close(cfd);

	return NULL;
}

int main(int argc, char *argv[])
{
	int sockfd,new_sockfd;
	unsigned int port = 0;
	struct sockaddr_in address,new_address;
	socklen_t addrlen;
	pthread_t tid;

	if(argc!=2||!(port=atoi(argv[1])))
	{
		cerr<<"Usage: "<<argv[0]<<" [port-number]"<<endl;
		return 1;
	}

	// create socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==0)
	{
		perror("Create socket");
		return 1;
	}

	// bind the socket to the given port
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=INADDR_ANY;
	address.sin_port=htons(port);
	if(bind(sockfd,(struct sockaddr *)&address,sizeof(address)))
	{
		perror("Bind");
		return 1;
	}

	// Listen to the port
	if(listen(sockfd,LISTENQUEUENUM))
	{
		perror("Listen");
		return 1;
	}

	// Accept connection
	while(1)
	{
		addrlen=sizeof(sockaddr_in);
		new_sockfd=accept(sockfd,(struct sockaddr *)&new_address,&addrlen);
		if(new_sockfd<0)
			perror("Accept connection");
		else
		{
			if(pthread_create(&tid,NULL,thread,&new_sockfd))
			{
				perror("Create threads");
				close(new_sockfd);
				close(sockfd);
				return 1;
			}
			if(pthread_detach(tid))
			{
				perror("Detach threads");
				close(new_sockfd);
				close(sockfd);
				return 1;
			}
		}
	}

	// Close the socket
	close(sockfd);

	return 0;
}

