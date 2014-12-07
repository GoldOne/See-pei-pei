/*
•Student name Yi Jin 
•Student number 4370673
•Lab Monday 830AM-1030AM
*/
#include <iostream>

class LLONG
{
	public:
		LLONG();
		LLONG(int);
		LLONG(const LLONG &);
		~LLONG();
		void add(const LLONG &);
		void subtract(const LLONG &);
		void multiply(const LLONG &);
		void divide(const LLONG &);
		void mod(const LLONG &);
		std::ostream & output (std::ostream &);
		int compare(const LLONG &);
		// return 0 for equal, 1 for >, -1 for <
	private:
		double number;
		int exponent;
		void Convert();
};