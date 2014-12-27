#include<ctime>
#include"wrappers.h"
using namespace std;

void printTitle()
{
	printf("%8s%24s%24s\n","Line No.","Miss-spelt word","Suggestion");
	fflush(stdout);
}

void printLine(char* buffer)
{
	char* p;
	p=strtok(buffer,DELIMITER);
	printf("%8s",p);
	p=strtok(NULL,DELIMITER);
	printf("%24s",p);
	p=strtok(NULL,DELIMITER);
	printf("%24s\n",p);
	fflush(stdout);
}

int main(int argc, char* argv[])
{
	clock_t start,end;
	start=clock();

	unsigned int port=0;
	int sock_fd, file_fd;
	struct sockaddr_in address;
	struct hostent *hent;
	uint32_t filesize=0;
	char buffer[BUFFERLENGTH];
	int ret;

	if(argc!=5||!(port=atoi(argv[2])))
	{
		cerr<<"Usage: "<<argv[0]<<" [hostname] [port-number] [filename] [NumOfThread]  "<<endl;
		return 1;
	}

	// open the document file and get the size
	file_fd=open(argv[3],O_RDONLY);
	if(file_fd<0)
	{
		perror("Open file");
		return 1;
	}
	filesize=lseek(file_fd,0,SEEK_END);

	// create socket
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd==0)
	{
		perror("Create socket");
		return 1;
	}

	// connect to server
	hent=gethostbyname(argv[1]);
	if (!hent)
	{
		cerr<<"Can't find the host."<<endl;
		return 1;
	}
	memcpy(&address.sin_addr,hent->h_addr_list[0],hent->h_length);
	address.sin_family=AF_INET;
	address.sin_port=htons(port);
	if(connect(sock_fd,(struct sockaddr*)&address,sizeof(address))< 0)
	{
		perror("Connect to server");
		return 1;
	}

	// send the file size to server
	filesize=htonl(filesize);
	if(write(sock_fd,&filesize, sizeof(filesize))< 0)
	{
		perror("Send data");
		return 1;
	}

	// send the content of the document
	lseek(file_fd,0,SEEK_SET);
	while((ret=read(file_fd,buffer,sizeof(buffer)))>0)
		write(sock_fd,buffer,ret);


	// receive the result of checking words, when get FINISHSIGN to finish
	printTitle();
	if(read(sock_fd,buffer,sizeof(buffer))<0)
	{
		perror("Receive the result");
		return 1;
	}
	while(strncmp(buffer,FINISHSIGN,strlen(FINISHSIGN)))
	{
		printLine(buffer);
		if(read(sock_fd,buffer,sizeof(buffer))<0)
		{
			perror("Receive the result");
			return 1;
		}
	}

	// close the socket and document
	close(sock_fd);
	close(file_fd);

	end=clock();

	cout<<"Total processing time = "<<double(end-start)/CLOCKS_PER_SEC<<" sec"<<endl;

	return 0;
}

