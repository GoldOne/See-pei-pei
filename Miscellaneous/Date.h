//Yi Jin,4370673
#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
namespace MyLib
{
	class Date
	{
		private:
			int day;
			int month;
			int year;
		public:
			Date(){};
			void setDate(int d,int m,int y){day=d;month=m;year=y;};
			void setDate(const std::string &);
			void validDate();
			void toString();
			std::string getDate();
	};
}
#endif
