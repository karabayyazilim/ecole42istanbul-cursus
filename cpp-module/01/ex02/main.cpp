#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("HI THIS IS BRAIN");
    string* stringPTR = &str;
    string& stringREF = str;

    cout << "Memory adress of string: " << &str << endl;
    cout << "Memory adress of stringPTR: " << stringPTR << endl;
    cout << "Memory adress of stringREF: " << &stringREF << endl;

    cout << "Value of the string: " << str << endl;
    cout << "Value of the stringPTR: " << *stringPTR << endl;
    cout << "Value of the stringREF: " << stringREF << endl;
}