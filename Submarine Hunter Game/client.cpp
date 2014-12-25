#include"wrappers.h"
#include<ctime>
int main(int argc,char *argv[])
{
	int Sockfd;
	sockaddr_in ServAddr;
	char ServHost[256];
	if(argv[1]!=NULL)
		strcpy(ServHost,argv[1]);
	else
	 	strcpy(ServHost,"localhost");
	hostent *HostPtr;
	int Port=70673;
	
	char flag[MAX_SIZE]="n";
	char score[MAX_SIZE]; 

	HostPtr = Gethostbyname(ServHost);

	if(HostPtr->h_addrtype !=  AF_INET)
	{
		perror("Unknown address type!");
		exit(1);
	}

	memset((char *) &ServAddr, 0, sizeof(ServAddr));
	ServAddr.sin_family = AF_INET;
	ServAddr.sin_addr.s_addr = ((in_addr*)HostPtr->h_addr_list[0])->s_addr;
	if(argc==3)
		Port=atoi(argv[2]);
	ServAddr.sin_port = htons(Port);

	Sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	Connect(Sockfd, (sockaddr*)&ServAddr, sizeof(ServAddr));

	int x,y,a,b;//players position x,y for player a,b for computer
	int X,Y,A,B;//Torpedo position
	int pscore=0;
	int cscore=0;
	char map[7][7];
	srand(time(NULL));//set seed
	x=rand()%7;//initial player position
	y=rand()%7;

	do
	{
		a=rand()%7;
		b=rand()%7;
	}while(a==x&&b==y);//initial computer position and not the same as the player's

	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
			map[i][j]='+';//initial map

	map[x][y]='P';//mark player's position

	char command;
	
	for(int i=0;i<7;i++)//draw map
	{
		for(int j=0;j<7;j++)
			cout<<map[i][j]<<" ";

		switch (i)
		{
			case 0:
				cout<<"          SCORES"<<endl;
				break;
			case 1:
				cout<<"      Player  Computer"<<endl;
				break;
			case 2:
				cout<<"        "<<pscore<<"        "<<cscore<<endl;
				break;
			case 3:
				cout<<endl;
				break;
			case 4:
				cout<<"    P = Player's Position"<<endl;
				break;
			case 5:
				cout<<"    p = Player's Torpedo"<<endl;
				break;
			case 6:
				cout<<"    c = Computer's Torpedo"<<endl;
				break;
		}
	}

	cout<<endl<<"(f)ire (l)eft (r)ight (u)p (d)own (s)urrender"<<endl;
	cout<<"Enter your move =>";

	do
	{
		if(pscore==5)
		{
			cout<<"You win!"<<endl;
			close(Sockfd);
			break;
		}

		if(cscore==5)
		{
			cout<<"I win!"<<endl;
			close(Sockfd);
			break;
		}

		cin>>command;

		switch(command)
		{
			case 'f':
				
				char junk;
				cout<<"Please enter the target position (x,y) for torpedo: ";
				cin>>X>>junk>>Y;
				map[X][Y]='p';
				
				break;
			case 'l':
				if(y>0)
				{
					map[x][y]='+';
					y--;
					map[x][y]='P';
				}
				break;
			case 'r':
				if(y<6)
				{
					map[x][y]='+';
					y++;
					map[x][y]='P';
				}
				break;
			case 'u':
				if(x>0)
				{
					map[x][y]='+';
					x--;
					map[x][y]='P';
				}
				break;
			case 'd':
				if(x<6)
				{
					map[x][y]='+';
					x++;
					map[x][y]='P';
				}
				break;
			case 's':
				strcpy(flag,"q");
				write(Sockfd,flag, sizeof(flag));
				close(Sockfd);
				break;
		}

		if(command=='s')
			break;

		score[0]=pscore+0x30;
		score[1]=cscore+0x30;
		score[2]=a+0x30;
		score[3]=b+0x30;
		score[4]='\0';
		write(Sockfd,score, sizeof(score));
		read(Sockfd,score,sizeof(score));

		char temp[2];
		switch(score[0])
		{
			case 'm':
				temp[0]=score[1];
				temp[1]='\0';
				a=atoi(temp);
				temp[0]=score[2];
				b=atoi(temp);
				break;
			case 'f':
				temp[0]=score[1];
				temp[1]='\0';
				A=atoi(temp);
				temp[0]=score[2];
				B=atoi(temp);
				break;
		}

		if(X==a&&Y==b)
			pscore++;

		if(x==A&&y==B)
			cscore++;
		else
			map[A][B]='c';

		for(int i=0;i<7;i++)
		{
			for(int j=0;j<7;j++)
				cout<<map[i][j]<<" ";

			switch (i)
			{
				case 0:
					cout<<"          SCORES"<<endl;
					break;
				case 1:
					cout<<"      Player  Computer"<<endl;
					break;
				case 2:
					cout<<"        "<<pscore<<"        "<<cscore<<endl;
					break;
				case 3:
					cout<<endl;
					break;
				case 4:
					cout<<"    P = Player's Position"<<endl;
					break;
				case 5:
					cout<<"    p = Player's Torpedo"<<endl;
					break;
				case 6:
					cout<<"    c = Computer's Torpedo"<<endl;
					break;
			}
		}

		cout<<endl<<"(f)ire (l)eft (r)ight (u)p (d)own (s)urrender"<<endl;
		cout<<"Enter your move =>";
		
		if(x!=A&&y!=B)
			map[A][B]='+';

		map[X][Y]='+';

	}while(command!='s');
	
	if(command=='s')
		cout<<"You surrendered Computer win!!!"<<endl;

	return 0;
}
