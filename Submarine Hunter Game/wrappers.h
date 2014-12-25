#include<unistd.h>     
#include<sys/types.h>  
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<netdb.h>     
#include<arpa/inet.h> 
#include<signal.h>     
#include<sys/signal.h> 
#include<errno.h>     
#include<cstdlib>      
#include<cctype>     
#include<cstring>
#include<sys/wait.h>      
#include<iostream>    
using namespace std;

const int MAX_SIZE=256; 

int Socket(int Domain, int Type, int Protocol);
void Bind(int Sockfd, sockaddr *MyAddr, int AddrLen);
void Listen(int Sockfd, int Backlog);
void Connect(int Sockfd, sockaddr *ServAddr, int Size);
int Accept(int Sockfd, sockaddr *Addr, int *AddrLen);
hostent *Gethostbyname(char *ServHost);
