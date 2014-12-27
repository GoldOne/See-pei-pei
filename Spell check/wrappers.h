#ifndef _WRAPPERS_H_
#define _WRAPPERS_H_
#include<cctype>   
#include<netdb.h>  
#include<stdio.h>
#include<cstring>
#include<errno.h> 
#include<cstdlib> 
#include<fcntl.h>
#include<unistd.h>  
#include<stdlib.h>
#include<signal.h>
#include<iostream>  
#include<sys/wait.h>    
#include<sys/stat.h>
#include<sys/types.h> 
#include<arpa/inet.h>
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<sys/signal.h> 
using namespace std;

const char FINISHSIGN[]="FINISH";
const int BUFFERLENGTH=1024;
const char DELIMITER[]=";";

void wrapString(char* buffer, int lineno, const char* word1, const char* word2);
#endif

