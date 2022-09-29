#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
#include <string>
#include <strings.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Contact
{
public:
    const string& getFirstName();
    void setFirstName(const string& firstName);
    const string& getLastName();
    void setLastName(const string& lastName);
    const string& getNickName();
    void setNickName(const string& nickName);
    const string& getPhoneNumber();
    void setPhoneNumber(const string& phoneNumber);
    const string& getDarkestSecret();
    void setDarkestSecret(const string& darkestSecret);

private:
    string _firstName;
    string _lastName;
    string _nickName;
    string _phoneNumber;
    string _darkestSecret;
};



#endif
