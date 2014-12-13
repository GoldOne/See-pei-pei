//Yi Jin,4370673
#include<iostream>
class Binary
{
	friend  std::ostream& operator<<(std::ostream&,Binary &);

	private:
		int sign;
		int length;
		int* binarycode;
		void operator>>(char []);
		void operator>>(std::string);
	public:
		Binary() {sign=0; length=0;};
		Binary(char []);
		Binary(std::string); 
		Binary(const Binary &);
		~Binary() {delete [] binarycode;};
		void operator!();
		void operator<<(int);
		void operator>>(int);
		void operator~();
		Binary operator+(const Binary &);
		Binary operator-(const Binary &);
		Binary operator=(const Binary &);
		Binary operator+=(const Binary &);
		Binary operator-=(const Binary &);
		Binary operator*(const Binary &);
		Binary operator*=(const Binary &);
}; 
