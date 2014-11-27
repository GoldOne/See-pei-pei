/************************************************************************************* 
* Filename: yahtzeegame.cpp *
* Modification Date: 14/05/2013 *
* Purpose of this file (or program): produce a program for playing the game Yahtzee.*
*************************************************************************************/
#include <iostream>

#include "yahtzee.h"

using namespace std;

extern int finalscore;

extern int bonus;

int main()

{
	enterseed();//input seed

	for (int j=1;j<=13;j++)
	{
		cout<<"Round "<<j<<endl;
	
		rolling();

		rules();
		
	}	

	if(bonus>=63)

	cout<<"Your final score is "<<finalscore<<"+ Bonus 35: "<<finalscore+35<<endl;

	else cout<<"Your final score is "<<finalscore<<"."<<endl;//ouput the final score

	return 0;
}		

