#include <iostream>
#include <string.h>

std::string& strreplace(std::string& str, const char* s1, const char* s2)
{
    size_t index = 0;
    size_t len = strlen(s1);
    while ((index = str.find(s1,index)) && index != str.npos)
    {
        str = str.substr(0,index) + s2 + str.substr(index + len);
        index += len;
    }
    return str;
}