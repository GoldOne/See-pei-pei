/************************************************************************************* 
* Filename: driver.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): function for encrypt and decrypt.*
*************************************************************************************/
#include <iostream>

#include <fstream>

using namespace std;

extern int length;//extern the variables

extern char input[256];

extern char output[256];

void vignere_encrypt(char endata[], char enkey[])

{
	char encrypt[1024];

	ofstream out;

	cout<<"Encrypting "<<input<<" -- writing output to "<<output<<endl;	

	for (int i=0,j=0;i<1024;i++,j++)//encrypting the code
	{
		if (endata[i]>='A' && endata[i]<='Z')
		{
			if(j>length-1)
			{
				j=0;				
				encrypt[i]=(endata[i]+enkey[j])%26+65;
			}

			else	encrypt[i]=(endata[i]+enkey[j])%26+65;
		}
		else encrypt[i]=endata[i];//ingore the space and other signs
	}
	
	out.open(output);

	if (out.good())//output the encrypting result
	{

		out<<encrypt<<endl;

		out.close();
	}
		
	cout<<"Done..."<<endl;
	
}

void vignere_decrypt(char dedata[], char dekey[])
{
	char decrypt[1024];

	ofstream out;

	cout<<"Decrypting "<<input<<" -- writing output to "<<output<<endl;	

	for (int i=0,j=0;i<1024;i++,j++)//decrypting the code
	{
		if (dedata[i]>='A' && dedata[i]<='Z')
		{
			if(j>length-1)
			{
				j=0;	
				if (dedata[i]-dekey[j]<0)
				decrypt[i]=(dedata[i]-dekey[j])%26+65+26;
				else decrypt[i]=(dedata[i]-dekey[j])%26+65;
				
			}
			
			else if (dedata[i]-dekey[j]<0)
				decrypt[i]=(dedata[i]-dekey[j])%26+65+26;
			     else decrypt[i]=(dedata[i]-dekey[j])%26+65;
		}
		else decrypt[i]=dedata[i];//ingore the space and other signs
	}
	
	out.open(output);

	if (out.good())//output the encrypting result
	{

		out<<decrypt<<endl;

		out.close();
	}
		
	
	cout<<"Done..."<<endl;
	
} 
