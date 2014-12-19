#include <cstdlib>
#include <iostream>
#include "AccountManagement.h"
 
int main(int argc, char *argv[])
{
    if(argc != 3) {
        std::cout << "USAGE: " << argv[0] << " input-text-file output-binary-file" << std::endl;
        return 0;
    }
    
    AccountManagement admin;
    
    admin.loadData(argv[1]);
    admin.displayData();
    admin.saveData(argv[2]);
    
   // system("PAUSE");
    return EXIT_SUCCESS;
}
