/************************************************************************************* 
* Filename: yahtzee.cpp * 
* Student's first name: Yi  * 
* Modification Date: 14/05/2013 *
* Purpose of this file (or program): produce a program for playing the game Yahtzee.*
*************************************************************************************/
#include <iostream>

#include <cstdlib>

using namespace std;

int finalscore=0;

int bonus=0;

int num[14]={0};

int temp[13]={0};	

int dice[5];

int roll[5];

int r=0;

int k=0;

void enterseed()
{
	cout<<"Please enter five values in the range 1 to 6 (seperate with space and end with a number without 0): "<<endl;

	int i=0;	

	cin>>dice[i];//input seed

	while (i<5)
	{
		switch(dice[i])
		{
			case 0:		cout<<"Please enter the values between 1 to 6"<<endl;
					cin>>dice[i];
			break;
			case 1:		i++;
					cin>>dice[i];
			break;
			case 2:		i++;
					cin>>dice[i];
			break;
			case 3:		i++;
					cin>>dice[i];
			break;
			case 4:		i++;
					cin>>dice[i];
			break;
			case 5:		i++;
					cin>>dice[i];
			break;
			case 6:		i++;
					cin>>dice[i];
			break;
			case 7:		cout<<"Please enter the values between 1 to 6"<<endl;
					cin>>dice[i];
			break;
			case 8:		cout<<"Please enter the values between 1 to 6"<<endl;
					cin>>dice[i];
			break;
			case 9:		cout<<"Please enter the values between 1 to 6"<<endl;
					cin>>dice[i];
			break;
			default: 	cout<<"Please enter the correct number."<<endl;
		}
	}
	cout<<"Yahtzee Program"<<endl;

	cout<<"Enter Seed :";

	for (int i=0;i<5;i++)
	{
		cout<<dice[i];
	}
	cout<<endl;
}

void rolling()
{
	char rolls[5];	

	cout<<"The dice were ";

	int seed=(dice[0]*10000+dice[1]*1000+dice[2]*100+dice[3]*10+dice[4]-r)*r;

	r++;		

	srand(seed);	

	for (int i=0;i<5;i++)
	{
		roll[i]=rand()% 6 + 1;//create random number from 1 to 6

		cout<<roll[i];
	}
		cout<<endl;

		cout<<"what re-rolls?";

		cin.ignore();//ignore space

	for(int i=0;i<5;i++)
	{
		cin>>rolls[i];

		if (rolls[i]=='r')

		roll[i]=rand()% 6 + 1;//rerolling 
	}
	cout<<"The dice were ";

	for (int i=0;i<5;i++)
	{
		cout<<roll[i];
	}
	cout<<endl;
}

void rules()
{
	int score[6]={0};	

	static int count;

	if (num[0]!=1&&num[1]!=1&&num[2]!=1&&num[3]!=1&&num[4]!=1&&num[5]!=1&&num[6]!=1&&num[7]!=1&&num[8]!=1&&num[9]!=1&&num[10]!=1&&num[11]!=1&&num[12]!=1)
		cout<<"1.   "<<"Aces"<<endl;
	if (num[0]!=2&&num[1]!=2&&num[2]!=2&&num[3]!=2&&num[4]!=2&&num[5]!=2&&num[6]!=2&&num[7]!=2&&num[8]!=2&&num[9]!=2&&num[10]!=2&&num[11]!=2&&num[12]!=2)
		cout<<"2.   "<<"Twos"<<endl;
	if (num[0]!=3&&num[1]!=3&&num[2]!=3&&num[3]!=3&&num[4]!=3&&num[5]!=3&&num[6]!=3&&num[7]!=3&&num[8]!=3&&num[9]!=3&&num[10]!=3&&num[11]!=3&&num[12]!=3)
		cout<<"3.   "<<"Threes"<<endl;
	if (num[0]!=4&&num[1]!=4&&num[2]!=4&&num[3]!=4&&num[4]!=4&&num[5]!=4&&num[6]!=4&&num[7]!=4&&num[8]!=4&&num[9]!=4&&num[10]!=4&&num[11]!=4&&num[12]!=4)
		cout<<"4.   "<<"Fours"<<endl;
	if (num[0]!=5&&num[1]!=5&&num[2]!=5&&num[3]!=5&&num[4]!=5&&num[5]!=5&&num[6]!=5&&num[7]!=5&&num[8]!=5&&num[9]!=5&&num[10]!=5&&num[11]!=5&&num[12]!=5)
		cout<<"5.   "<<"Fives"<<endl;
	if (num[0]!=6&&num[1]!=6&&num[2]!=6&&num[3]!=6&&num[4]!=6&&num[5]!=6&&num[6]!=6&&num[7]!=6&&num[8]!=6&&num[9]!=6&&num[10]!=6&&num[11]!=6&&num[12]!=6)
		cout<<"6.   "<<"Sixes"<<endl;
	if (num[0]!=7&&num[1]!=7&&num[2]!=7&&num[3]!=7&&num[4]!=7&&num[5]!=7&&num[6]!=7&&num[7]!=7&&num[8]!=7&&num[9]!=7&&num[10]!=7&&num[11]!=7&&num[12]!=7)
		cout<<"7.   "<<"3 of a kind"<<endl;
	if (num[0]!=8&&num[1]!=8&&num[2]!=8&&num[3]!=8&&num[4]!=8&&num[5]!=8&&num[6]!=8&&num[7]!=8&&num[8]!=8&&num[9]!=8&&num[10]!=8&&num[11]!=8&&num[12]!=8)
		cout<<"8.   "<<"4 of a kind"<<endl;
	if (num[0]!=9&&num[1]!=9&&num[2]!=9&&num[3]!=9&&num[4]!=9&&num[5]!=9&&num[6]!=9&&num[7]!=9&&num[8]!=9&&num[9]!=9&&num[10]!=9&&num[11]!=9&&num[12]!=9)
		cout<<"9.   "<<"Full House"<<endl;
	if (num[0]!=10&&num[1]!=10&&num[2]!=10&&num[3]!=10&&num[4]!=10&&num[5]!=10&&num[6]!=10&&num[7]!=10&&num[8]!=10&&num[9]!=10&&num[10]!=10&&num[11]!=10&&num[12]!=10)
		cout<<"10.  "<<"Small Straight"<<endl;
	if (num[0]!=11&&num[1]!=11&&num[2]!=11&&num[3]!=11&&num[4]!=11&&num[5]!=11&&num[6]!=11&&num[7]!=11&&num[8]!=11&&num[9]!=11&&num[10]!=11&&num[11]!=11&&num[12]!=11)
		cout<<"11.  "<<"Large Straight"<<endl;
	if (num[0]!=12&&num[1]!=12&&num[2]!=12&&num[3]!=12&&num[4]!=12&&num[5]!=12&&num[6]!=12&&num[7]!=12&&num[8]!=12&&num[9]!=12&&num[10]!=12&&num[11]!=12&&num[12]!=12)
		cout<<"12.  "<<"Yahtzee"<<endl;
	if (num[0]!=13&&num[1]!=13&&num[2]!=13&&num[3]!=13&&num[4]!=13&&num[5]!=13&&num[6]!=13&&num[7]!=13&&num[8]!=13&&num[9]!=13&&num[10]!=13&&num[11]!=13&&num[12]!=13)
		cout<<"13.  "<<"Chance"<<endl;//13 options for recording scores
		
	cout<<endl;

	int sum=0;
		
	for (int i=0;i<5;i++)
	{
		sum+=roll[i];

		switch(roll[i])
		{
			case 1:		score[0]++;//satistic the different number of result of rolls
			break;
			case 2:		score[1]++;
			break;
			case 3:		score[2]++;
			break;
			case 4:		score[3]++;
			break;
			case 5:		score[4]++;
			break;
			case 6:		score[5]++;
			break;
		}
	}
		
	cout<<"Which category? ";

	cin>>num[k];
						
	while(num[k]==temp[0]||num[k]==temp[1]||num[k]==temp[2]||num[k]==temp[3]||num[k]==temp[4]||num[k]==temp[5]||num[k]==temp[6]||num[k]==temp[7]||num[k]==temp[8]||num[k]==temp[9]||num[k]==temp[10]||num[k]==temp[11]||num[k]==temp[12])
	{
		cout<<"Bad Catergory Please retry? ";//elminate the used options for next round

		cin>>num[k];
	}

	while(num[k]<1 || num[k]>13)
	{
		cout<<"Bad Catergory Please retry? ";//bad category handling.

		cin>>num[k];
	}
				
	temp[k]=num[k];//store the options which have been input

	if (num[k]<7)//prepraing for the first six categories.

		count++;

	switch(num[k])//determine which way for calculating the finalscore.
	{
		case 1:		cout<<"Score recorded for round: "<<score[0]<<endl;
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;

				finalscore+=score[0];					
				bonus+=score[0];
		break;
		case 2:		cout<<"Score recorded for round: "<<score[1]*2<<endl;
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;

				finalscore+=score[1]*2;
				bonus+=score[1]*2;
		break;
		case 3:		cout<<"Score recorded for round: "<<score[2]*3<<endl;
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;

				finalscore+=score[2]*3;
				bonus+=score[2]*3;
		break;
		case 4:		cout<<"Score recorded for round: "<<score[3]*4<<endl;
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;

				finalscore+=score[3]*4;
				bonus+=score[3]*4;
		break;
		case 5:		cout<<"Score recorded for round: "<<score[4]*5<<endl;
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;

				finalscore+=score[4]*5;
				bonus+=score[4]*5;
		break;
		case 6:		cout<<"Score recorded for round: "<<score[5]*6<<endl;
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;

				finalscore+=score[5]*6;
				bonus+=score[5]*6;
		break;
		case 7:		if(score[0]==3||score[1]==3||score[2]==3||score[3]==3||score[4]==3||score[5]==3)
				{		
				cout<<"Score recorded for round: "<<sum<<endl;
				finalscore+=sum;
				}
				else{
					cout<<"Score recorded for round: 0"<<endl;
				 	finalscore+=0;
				    }
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;
					
		break;
		case 8:		if(score[0]==4||score[1]==4||score[2]==4||score[3]==4||score[4]==4||score[5]==4)
				{		
					cout<<"Score recorded for round: "<<sum<<endl;
					finalscore+=sum;
				}
				else{
					cout<<"Score recorded for round: 0"<<endl;
					finalscore+=0;
				    }
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;
					
		break;
		case 9:	if((roll[0]==roll[1])and(roll[1]==roll[2])and(roll[3]==roll[4])and(roll[0]!=roll[4])||(roll[0]==roll[1])and(roll[2]==roll[3])and(roll[3]==roll[4])and(roll[0]!=roll[4])||(roll[0]==roll[2])and(roll[2]==roll[4])and(roll[1]==roll[3])and(roll[0]!=roll[1])||(roll[0]==roll[2])and(roll[1]==roll[3])and(roll[3]==roll[4])and(roll[0]!=roll[1])||(roll[0]==roll[3])and(roll[3]==roll[4])and(roll[1]==roll[2])and(roll[0]!=roll[1])||(roll[0]==roll[1])and(roll[2]==roll[3])and(roll[1]==roll[4])and(roll[0]!=roll[2])||(roll[0]==roll[1])and(roll[1]==roll[3])and(roll[2]==roll[4])and(roll[0]!=roll[2])||(roll[0]==roll[4])and(roll[1]==roll[2])and(roll[2]==roll[3])and(roll[0]!=roll[1])||(roll[0]==roll[3])and(roll[1]==roll[2])and(roll[2]==roll[3])and(roll[0]!=roll[1])||(roll[0]==roll[2])and(roll[2]==roll[3])and(roll[1]==roll[4])and(roll[0]!=roll[1]))
				{		
					cout<<"Score recorded for round: 25"<<endl;
					finalscore+=25;
				}
				else{	cout<<"Score recorded for round: 0"<<endl;
					finalscore+=0;
				    }
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;    
		break;
		case 10:	if((roll[0]-roll[1]==1 and roll[1]-roll[2]==1 and roll[2]-roll[3]==1)||(roll[1]-roll[0]==1 and roll[2]-roll[1]==1 and roll[3]-roll[2]==1)||(roll[1]-roll[2]==1 and roll[2]-roll[3]==1 and roll[3]-roll[4]==1)||(roll[2]-roll[1]==1 and roll[3]-roll[2]==1 and roll[4]-roll[3]==1))
				{		
					cout<<"Score recorded for round: 30"<<endl;
					finalscore+=30;
				}
				else{
					cout<<"Score recorded for round: 0"<<endl;
					finalscore+=0;
				    }
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;
		break;
		case 11:	if((roll[0]-roll[1]==1 and roll[1]-roll[2]==1 and roll[2]-roll[3]==1 and roll[3]-roll[4]==1)||(roll[1]-roll[0]==1 and roll[2]-roll[1]==1 and roll[3]-roll[2]==1 and roll[4]-roll[3]==1))
				{		
					cout<<"Score recorded for round: 40"<<endl;
					finalscore+=40;
				}
				else{
					cout<<"Score recorded for round: 0"<<endl;
					finalscore+=0;
				    }
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;
		break;
		case 12:	if(score[0]==5||score[1]==5||score[2]==5||score[3]==5||score[4]==5||score[5]==5)
				{		
					cout<<"Score recorded for round: 50"<<endl;
					finalscore+=50;
				}
				else{
					cout<<"Score recorded for round: 0"<<endl;
					finalscore+=0;
				    }
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;
		break;
		case 13:	cout<<"Score recorded for round: "<<sum<<endl;
				finalscore+=sum;
				if(count==6)
				cout<<"Score for first six Categories: "<<bonus<<endl;
				else
				cout<<"Score for first six Categories: 0"<<endl;
		break;
	}
					
	sum=0;//reset the score for each round.
	
	k++;
}

