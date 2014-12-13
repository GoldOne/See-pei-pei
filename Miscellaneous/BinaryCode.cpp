//Yi Jin,4370673
#include"BinaryCode.h"
#include<cmath>
#include<string>
#include<cctype>
#include<cstdlib>
#include<sstream>
using namespace std;

void Binary::operator>>(char num[])
{
	int number;

	if(isdigit(num[0]))//if it is positive number
	{
		number=atoi(num);
		int temp=number;
		int count=0;
		
		sign=0;
		while(temp!=0&&temp!=1)
		{
			temp/=2;
			count++;
		}//count the length 

		length=count+1;

		binarycode=new int[length];
		int* num=new int[length];
		
		for(int i=0;i<length;i++)
		{
			num[i]=number%2;
			number/=2;
		}//change to the binary

		for(int i=length-1,j=0;i>=0;i--,j++)
			binarycode[j]=num[i];

		delete [] num;
	}
	else
	{
		char temp[256];
		for(int i=1,j=0;i<256;i++,j++)
			temp[j]=num[i];//remove the negetive sign
		operator>>(temp);
		operator!();
	}
}

ostream& operator<<(ostream& out,Binary &b)
{
	out<<b.sign;
	for(int i=0;i<b.length;i++)
		out<<b.binarycode[i];
	out<<endl;
	
	return out;
}

Binary::Binary(char num[])
{
	operator>>(num);
}

Binary::Binary(string b)
{
	operator>>(b);
}

void Binary::operator!()
{
	for(int i=0;i<length;i++)//invert Binary
	{
		if(binarycode[i]==0)
			binarycode[i]=1;
		else
			binarycode[i]=0;
	}

	sign==0?sign=1:sign=0;
}

void Binary::operator~()
{
	binarycode[length-1]++;
	
	for(int i=length-1;i>=0;i--)
	{
		if(binarycode[i]>1)
		{
			binarycode[i]-=2;
			binarycode[i-1]++;
		}
	}
}

Binary::Binary(const Binary &b)//deep copy constructor
{
	sign=b.sign;
	length=b.length;
	binarycode=new int[length];
	for(int i=0;i<length;i++)
		 binarycode[i]=b.binarycode[i];
}

void Binary::operator<<(int num)//intertion for a binary number
{
	int len=length;
	length+=num;
	int* temp=new int[length];
	for(int i=0;i<len;i++)
		temp[i]=binarycode[i];
	for(int i=len;i<length;i++)
		temp[i]=0;
	delete [] binarycode;
	binarycode=new int[length];
	for(int i=0;i<length;i++)
		binarycode[i]=temp[i];
	delete [] temp;	
}

void Binary::operator>>(int num)//extraction for a binary number
{
	length-=num;
}

void Binary::operator>>(string b)
{
	if(isdigit(b[0]))//check if it is positive
	{
		sign=0;
		length=b.length();
		binarycode=new int[length];

		for(int i=0;i<length;i++)
		{
			string temp=b.substr(i,1);
			binarycode[i]=atoi(temp.c_str());//store it into binary array
		}
	}
	else
	{
		b.erase(0,1);
		operator>>(b);
		operator!();
	}					
}

Binary Binary::operator+(const Binary &b)
{
	Binary temp(*this);

	if(temp.length>=b.length)//add first and check length for both
	{
		for(int i=temp.length-1,j=b.length-1;j>=0;i--,j--)
			temp.binarycode[i]+=b.binarycode[j];
	}
	else
	{
		Binary temp(b);

		for(int i=temp.length-1,j=length-1;j>=0;i--,j--)
			temp.binarycode[i]+=binarycode[j];

		for(int i=temp.length-1;i>0;i--)//make carry
		{
			if(temp.binarycode[i]>1)
			{
				temp.binarycode[i]-=2;
				if(i!=0)
					temp.binarycode[i-1]++;
			}
		}

		if(temp.binarycode[0]>1)//check whether need addtional space for result
		{
			int len=temp.length+1;

			int* Temp=new int[len];

			for(int i=1,j=0;j<temp.length;i++,j++)
				Temp[i]=temp.binarycode[j];

			Temp[0]=1;
			Temp[1]-=2;

			delete [] temp.binarycode;
			temp.length=len;
			temp.binarycode=new int[temp.length];

			for(int i=0;i<temp.length;i++)
				temp.binarycode[i]=Temp[i];

			delete [] Temp;
		}

		return temp;
	}

	for(int i=temp.length-1;i>0;i--)//make carry
	{
		if(temp.binarycode[i]>1)
		{
			temp.binarycode[i]-=2;
			if(i!=0)
				temp.binarycode[i-1]++;
		}
	}	

	if(temp.binarycode[0]>1)//check whether need addtional space for result
	{
		int len=temp.length+1;

		int* Temp=new int[len];

		for(int i=1,j=0;j<temp.length;i++,j++)
			Temp[i]=temp.binarycode[j];

		Temp[0]=1;
		Temp[1]-=2;
		delete [] temp.binarycode;

		temp.length=len;
		temp.binarycode=new int[temp.length];

		for(int i=0;i<temp.length;i++)
			temp.binarycode[i]=Temp[i];

		delete [] Temp;
	}

	return temp;
}

Binary Binary::operator-(const Binary &b)
{
	Binary temp(b);
	!temp;
	~temp;
	return *this+temp;
}

Binary Binary::operator=(const Binary &b)//overlading the deep copy constructor
{
	if(this==&b)
		return *this;
	if(binarycode!=NULL)
		delete [] binarycode;
	length=b.length;
	sign=b.sign;
	binarycode=new int[length];
	for(int i=0;i<length;i++)
		binarycode[i]=b.binarycode[i];

	return *this;
}

Binary Binary::operator+=(const Binary &b)
{
	*this=*this+b;
	return *this;
}

Binary Binary::operator-=(const Binary &b)
{
	*this=*this-b;
	return *this;
}

Binary Binary::operator*(const Binary &b)
{
	Binary result(*this);
	Binary Temp(b);
	bool flag=false;

	if(this->sign==1&&Temp.sign==1)//check the sign 
	{
		!*this;
		!Temp;
		flag=true;
	}	

	if(this->sign==1)
		!*this;
	if(Temp.sign==1)
		!Temp;

	for(int n=Temp.length-1;n>=0;n--)
	{
		if(Temp.binarycode[n]==1)//take out the number for each
		{
			unsigned long long number=0;

			for(int i=length-1;i>=0;i--)
			{
				if(binarycode[i]==0)
					continue;
				else
					number+=binarycode[i]*pow(10.0,length-1-i);
			}

			string num;
			stringstream ss;

			ss<<number;
			ss>>num;

			Binary temp(num);
			temp<<Temp.length-1-n;
		
			if(n==Temp.length-1)//add the objects each time depends on the multiplicand
				result=temp;
			else
				result+=temp;
		}
	}

	if(sign==b.sign||flag)//decide the sign for result
		result.sign=0;
	else 
		!result;

	return result;
}

Binary Binary::operator*=(const Binary &b)
{
	*this=*this*b;
	return *this;
}
