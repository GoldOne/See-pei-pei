//Yj742,4370673
#include<iostream>
#include<string>
#include"BinaryCode.h"
using namespace std;

int main()
{
	char decimal[256];
	string binary;
	cout<<"Input a decimal number for bc1: ";
	cin>>decimal;
	Binary bc1(decimal);
	cout<<"bc1 = "<<bc1;
	Binary bct1(bc1);
	!bct1;
	cout<<"!bc1 = "<<bct1;
	~bct1;
	cout<<"~bc1 = "<<bct1; 
	Binary bct13(bc1);
	bct13<<4;
	cout<<"bc1 << 4 = "<<bct13;
	Binary bct14(bct1);
	bct14>>2;
	!bct14;
	cout<<"bc1 >> 2 = "<<bct14;
	cout<<"Input a binary string for bc2: ";
	cin>>binary;
	Binary bc2(binary); 
	cout<<"bc2 = "<<bc2;
	Binary bct2(bc2);
	!bct2; 
	cout<<"!bc2 = "<<bct2;
	~bct2;
	cout<<"~bc2 = "<<bct2;
	Binary bct23(bc2);
	bct23<<3;
	cout<<"bc2 << 3 = "<<bct23;
	Binary bct24(bct2);
	bct24>>4;
	!bct24;
	cout<<"bc2 >> 4 = "<<bct24;
	Binary temp=bc1+bc2;
	cout<<"bc1 + bc2 = "<<temp;
	temp=bc1-bc2;
	cout<<"bc1 - bc2 = "<<temp;
	temp=bc1*bc2;
	cout<<"bc1 * bc2 = "<<temp; 
	Binary bc3=bc1;
	cout<<"bc3 = bc1 = "<<bc3; 
	bc3+=bc2;
	cout<<"bc3 += bc2 = "<<bc3;
	bc3=bc1;
	cout<<"bc3 = bc1 = "<<bc3; 
	bc3-=bc2;
	cout<<"bc3 -= bc2 = "<<bc3;
	bc3=bc1;
	cout<<"bc3 = bc1 = "<<bc3;
	bc3*=bc2;
	cout<<"bc3 *= bc2 = "<<bc3;

	return 0;
}
