#include <cstdlib>
#include <iostream>
#include "AccountMap.h"

int main(int argc, char *argv[])
{
    if(argc != 2) {
            std::cout << "USAGE: " << argv[0] << " input-binary-file" << std::endl;
    }
    AccountMap am;
    am.loadData(argv[1]);
    am.displayData();
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}
