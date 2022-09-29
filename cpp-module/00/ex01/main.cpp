#include <stdlib.h>
#include "PhoneBook.h"

const string& strToUpper(string& text)
{
    for(int i = text.length() - 1; i >= 0; i--)
        text[i] = toupper(text[i]);
    return text;
}

int main()
{
    PhoneBook phoneBook;
    string input;

    while(true)
    {
        cout << "Which process do you want" << endl;
        cout << "ADD - SEARCH - EXIT" << endl;
        std::getline(cin, input);
        strToUpper(input);
        if(input == "ADD"){
            string firstname,lastname,nickname,phonenumber,darkestsecret;
            cout << "Enter first name: ";
            std::getline(cin, firstname);
            cout << "Enter last name: ";
            std::getline(cin, lastname);
            cout << "Enter nickname: ";
            std::getline(cin, nickname);
            cout << "Enter phone number: ";
            std::getline(cin, phonenumber);
            cout << "Enter darkestsecret: ";
            std::getline(cin, darkestsecret);
            if(phoneBook.addContact(firstname,lastname,nickname,phonenumber,darkestsecret) == false)
                cout << "Empty field not allowed" << endl;
            else
                cout << firstname << " Added" << endl;
        }
        else if(input == "SEARCH"){
            string id;
            phoneBook.showContacts();
            cout << "Enter index: ";
            std::getline(cin, id);
            if(phoneBook.isNumber(id) == false || phoneBook.showContactID(atoi(id.c_str())) == false)
                cout << "Invalid index" << endl;
        }
        else if(input == "EXIT")
            break;
    }
}