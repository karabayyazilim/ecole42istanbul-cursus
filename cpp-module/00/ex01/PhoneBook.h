#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "Contact.h"

class PhoneBook {
public:
    PhoneBook();
    bool addContact(const string& firstname,const string& lastname,const string& nickname,const string& phonenumber,const string& darkestsecret);
    bool showContactID(int index);
    void showContacts();
    const string formatString(const string& text);
    bool isNumber(const string text);

private:
   Contact _contacts[8];
   int index;
   int size;
};


#endif
