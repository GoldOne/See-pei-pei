#include"wrappers.h"

void wrapString(char* buffer, int lineno, const char* word1, const char* word2)
{
    sprintf(buffer, "%d%c%s%c%s", lineno, DELIMITER[0], word1, DELIMITER[0], word2);
}

