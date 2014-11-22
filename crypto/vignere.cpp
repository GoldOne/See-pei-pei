/************************************************************************************* 
* Filename: vignere.cpp * 
* Student's first name: Yi  * 
* Lab: AUTM-CSCI114/MCS9114-CL/01 Tue from 8:30 to 10:30 * 
* Modification Date: 03/06/2013 *
* Purpose of this file (or program): main function for vignere.*
*************************************************************************************/
#include <iostream>

#include <fstream>

#include <cstring>

#include "vignere.h"

using namespace std;

int length=0;

char input[256];

char output[256];//globe variables

int main()

{
	char key[8];

	char data[1024];

	cout<<"Enter source file: ";
	cin>>input;

	cout<<"Enter target file: ";
	cin>>output;

	cout<<"What is the key: ";
	cin>>key;

	while (strlen(key)>8)//the length of key cannot over 8
	{
		cout<<"The key is too long, give a new key: ";
		cin>>key;
	}
	
	for(int i=0;i<8;i++)//change the key into upper case 
	{
		if (key[i]<123 && key[i]>96)	
		key[i]-=32;
	}

	length=strlen(key);
	
	ifstream in(input);

	if (in.good())//input original text
	{
		while(!in.eof())
		{
			in.getline(data,1024);
			in.ignore();
		}
		in.close();
	}
	else {
		cout<<"Bad loading the source file !"<<endl;
	
		return 0;
	     }
	
	for(int i=0;i<1024;i++)//change the text into upper case 
	{
		if (data[i]<123 && data[i]>96)	
		data[i]-=32;
	}

	char enter;

	cout<<"Encrypt or Decrypt (e/d) ?";

	cin>>enter;

	while (enter!='E' && enter!='e' && enter!='D' && enter!='d')
	{
		cout<<"Pleae enter e or d: ";//must enter e or d 

		cin>>enter;
	}
	
	if (enter=='E' || enter=='e')
	vignere_encrypt(data, key);

	if (enter=='D' || enter=='d')
	vignere_decrypt(data, key);
	
	return 0;

}
