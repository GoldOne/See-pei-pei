#include "Date.h"
#include <sstream>
#include <iomanip>
#include<cstdlib>
namespace MYLIB {
    bool isLeapYear(int y) {
        if(y % 4 != 0)
            return false;
        else if(y % 100 == 0 && y % 400 != 0)
            return false;
        else
            return true;
    }

    Date::Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    
    void Date::setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    
    //Convert a string "DD/MM/YYYY" to Date
    void Date::setDate(std::string &date) {
        std::string tmp;
        tmp = date.substr(0,2);
        day = atoi(tmp.c_str());
        tmp = date.substr(3,2);
        month = atoi(tmp.c_str());
        tmp = date.substr(6,4);
        year = atoi(tmp.c_str());
    }

    
    //Validate date
    bool Date::validateDate() {
        if(year < 0)
            throw(std::string("Invalid year"));
        if(month < 1 || month > 12)
            throw(std::string("Invalid month"));
         switch(month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: //Big months
               if(day < 1 || day > 31)
                   throw(std::string("Invalid day. Day should be between 1 and 31."));
               break;
            case 4: case 6: case 9: case 11:  //Small months
               if(day < 1 || day > 30)
                   throw(std::string("Invalid day. Day should be between 1 and 30."));
               break;
            case 2:
                if(isLeapYear(year)) {
                    if(day < 1 || day > 29)
                       throw(std::string("Invalid day. Day should be between 1 and 29."));
                }
                else {
                    if(day < 1 || day > 28)
                       throw(std::string("Invalid day. Day should between 1 and 28."));
                }
        }

        return true;
    }

    //Convert date to string
    std::string Date::toString() const {
        std::ostringstream sout;
        sout << std::setw(2) << std::setfill('0') << day;
        sout << '/';
        sout << std::setw(2) << std::setfill('0') << month;
        sout << '/';
        sout << std::setw(4) << std::setfill('0') << year;
        
        return sout.str();
    }

}
