#include <string>
#ifndef _MYLIB_
#define _MYLIB_

namespace MYLIB {
    class Date {
        private:
            int day;
            int month;
            int year;
        public:
            Date(int = 1, int = 1, int = 1900);
            void setDate(int =1, int =1, int =1900);
            void setDate(std::string &);
            bool validateDate();
            std::string toString() const;
    };

    bool isLeapYear(int);

}

#endif
