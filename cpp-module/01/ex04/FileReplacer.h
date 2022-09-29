#ifndef _FILEREPLACER_H_
#define _FILEREPLACER_H_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <errno.h>

class FileReplacer{
public:
    FileReplacer(std::string filepath);
    void replace(const char* s1, const char* s2);

private:
    unsigned short int open(std::fstream& file);
    unsigned short int read(std::fstream& file, std::string& buffer);
    unsigned short int create(const std::string& buffer);

    std::string _fileName;
    std::string _filePath;
};

std::string& strreplace(std::string& str, const char* s1, const char* s2);


#endif