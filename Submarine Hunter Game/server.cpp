#include"wrappers.h"
#include<ctime>
extern "C" void SigChldHandler( int Signum );//to prevent the child become zombie process

int main(int argc,char *argv[])
{
	int Sockfd, NewSockfd, ClntLen;
	sockaddr_in ClntAddr, ServAddr;
	srand(time(NULL));
	int Port=70673;
	if(argv[1]!=NULL)
		Port=atoi(argv[1]);
	
	char message[MAX_SIZE];
	int pscore,cscore,x,y,a,b;

	Sockfd = Socket(AF_INET, SOCK_STREAM, 0); 

	int opt=1; 
	setsockopt(Sockfd,SOL_SOCKET,SO_REUSEADDR,(char *)&opt,sizeof(opt));

	memset((char*)&ServAddr, 0, sizeof(ServAddr));
	ServAddr.sin_family = AF_INET;
	ServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ServAddr.sin_port = htons(Port);

	char host[100];
	gethostname(host, 100);
	cout<< "Binding to port \""<<Port<<"\" on host \""<<host<<'\"'<<endl;
	Bind(Sockfd, (sockaddr*) &ServAddr, sizeof(ServAddr));
	cout<<"Subhunter Game Server Starting..."<<endl;
	
	Listen(Sockfd, 5);

	signal(SIGCHLD, SigChldHandler);

	while(true)
	{
		ClntLen = sizeof(ClntAddr);
		cout<<"Waiting for player to connect...\n";
		NewSockfd = Accept(Sockfd, (sockaddr*)&ClntAddr, &ClntLen);
		cout<<"A Player connected!\n";
		
		if(NewSockfd==-1)
			continue;

		printf("Client connect:ip=%s, port=%d \n", inet_ntoa(ServAddr.sin_addr), ntohs(ServAddr.sin_port));

		pid_t pid=fork();

		if(pid < 0)
		{
			perror("Can't bind to local address!");
			exit(1);
		}
		else if(pid==0)
		{
			close(Sockfd);
		
			while(true)
			{
				read(NewSockfd, message, sizeof(message));

				if(isalnum(message[0]))//receive and seperate into socres and computer position
				{
					pscore=atoi(message)/1000;
					cscore=(atoi(message)-pscore*1000)/100;
					x=(atoi(message)-pscore*1000-cscore*100)/10;
					y=atoi(message)%10;

					if(pscore<3&&rand()%3)//computer AI
					{
						int tmp=rand()%4;
			
						switch(tmp)
						{
							case 0:
								if(y>0)
									y--;
								message[0]='m';
								message[1]=x+0x30;
								message[2]=y+0x30;
								message[3]='\0';
								write(NewSockfd,message,sizeof(message));
								break;
							case 1:
								if(y<6)
									y++;
								message[0]='m';
								message[1]=x+0x30;
								message[2]=y+0x30;
								message[3]='\0';
								write(NewSockfd,message,sizeof(message));
								break;
							case 2:
								if(x>0)
									x--;
								message[0]='m';
								message[1]=x+0x30;
								message[2]=y+0x30;
								message[3]='\0';
								write(NewSockfd,message,sizeof(message));
								break;
							case 3:
								if(x>6)
									x++;
								message[0]='m';
								message[1]=x+0x30;
								message[2]=y+0x30;
								message[3]='\0';
								write(NewSockfd,message,sizeof(message));
								break;
						}
					}
					else if(cscore<2)
					{
						if(!rand()%4)
						{
							message[0]='f';
							message[1]=x+0x30;
							message[2]=y+0x30;
							message[3]='\0';
							write(NewSockfd,message,sizeof(message));
						}
						else
						{
							int tmp=rand()%4;
			
							switch(tmp)
							{
								case 0:
									if(y>0)
										y--;
									message[0]='f';
									message[1]=x+0x30;
									message[2]=y+0x30;
									message[3]='\0';
									write(NewSockfd,message,sizeof(message));
									break;
								case 1:
									if(y<6)
										y++;
									message[0]='f';
									message[1]=x+0x30;
									message[2]=y+0x30;
									message[3]='\0';
									write(NewSockfd,message,sizeof(message));
									break;
								case 2:
									if(x>0)
										x--;
									message[0]='f';
									message[1]=x+0x30;
									message[2]=y+0x30;
									message[3]='\0';
									write(NewSockfd,message,sizeof(message));
									break;
								case 3:
									if(x>6)
										x++;
									message[0]='f';
									message[1]=x+0x30;
									message[2]=y+0x30;
									message[3]='\0';
									write(NewSockfd,message,sizeof(message));
									break;
							}
						}
					}
					else
					{
						int a=rand()%7;
						int b=rand()%7;
						message[0]='f';
						message[1]=a+0x30;
						message[2]=b+0x30;
						message[3]='\0';
						write(NewSockfd,message,sizeof(message));
					}	
				}

				if(message[0]=='q')
					break;
			}

			close(NewSockfd);
			cout<<"A Player disconnected!\n";
		}
	}

	return 0;
}

extern "C" void SigChldHandler( int Signum )
{
// Catch SIGCHLD signals so child processes don't become zombies.
	pid_t pid;
	int stat;
	while((pid = waitpid(-1, &stat, WNOHANG)) > 0 );
	return;
}
