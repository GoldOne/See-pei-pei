/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>
#include <cmath>
#include "llong.h"      

using namespace std;   
LLONG::LLONG()   
{   
	number=0;   
	exponent=0;   
}  
   
LLONG::LLONG(int num)   
{   
	number=num/1.0;   
    	exponent=0;   
    	Convert();   
}   
     
void LLONG::Convert()   
{   
	if(number==0) 
		return;   
	while(fabs(number)>=10)   
	{   
		number/=10;   
        	exponent+=1;   
    	}   
    	while(fabs(number)<1)   
    	{   
        	number*=10;   
        	exponent-=1;   
    	}	   
} 
 
LLONG::~LLONG()
{

}
 
void LLONG::add(const LLONG& num)   
{   
    	int multiple;   
       
	multiple=exponent-num.exponent;   
	
	if(multiple>0)     
		number+=num.number*pow(10,-multiple/1.0);      
	else   
	{   
		number=number*pow(10,multiple/1.0)+num.number;   
		exponent=num.exponent;   
	}   

	Convert(); 
	//output(cout<<"Result: ");  
} 
   
void LLONG::subtract(const LLONG& num)   
{   
	int multiple;   

	multiple=exponent-num.exponent; 
	  
	if(multiple>0)       
		number-=num.number*pow(10,-multiple/1.0);     
	else   
	{   
		number=number*pow(10,multiple/1.0)-num.number;   
		exponent=num.exponent;   
	}   

	Convert(); 
	//output(cout<<"Result: ");  
}  
   
void LLONG::multiply(const LLONG& num)   
{   
	number*=num.number;   
	exponent+=num.exponent;   

	Convert(); 
	//output(cout<<"Result: ");    
}  
   
void LLONG::divide(const LLONG& num)   
{      
	if (num.number==0) 
	{
		cout<<"You cannot divide anything by ZERO !!!"<<endl;
		return;
	}   
	number/=num.number;   
	exponent-=num.exponent;   

	Convert();   
	//output(cout<<"Result: ");
}  
 
void LLONG::mod(const LLONG &num)
{
	LLONG temp(*this);
	
	LLONG Temp(*this);
	
	temp.divide(num);
	
	LLONG a(temp.number);
	
	a.multiply(num);
	
	Temp.subtract(a);
	
	Temp.Convert();
	
	Temp.output(cout<<"Result: ");
}  

LLONG::LLONG(const LLONG& num)   
{   
	number=num.number;   
	exponent=num.exponent;      
}

std::ostream & LLONG::output (std::ostream &output)
{
	cout<<number<<"E"<<exponent<<endl;
	
	return output;	
}

int LLONG::compare(const LLONG &num)
{
	if(number>=0 &&num.number>=0)
	{
		if(exponent>num.exponent)
			return 1;
		else if(exponent<num.exponent)
			return -1;
		else
		{
			if(number==num.number)
				return 0;
			else
				return number>num.number?1:-1;
		}
	}
	else if(number<0 &&num.number<0)
	{
		if(exponent>num.exponent)
			return -1;
		else if(exponent<num.exponent)
			return 1;
		else
		{
			if(number==num.number)
				return 0;
			else
				return number>num.number?1:-1;
		}
		
	}
	return number>num.number?1:-1;
}