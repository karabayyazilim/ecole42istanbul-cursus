#include "Harl.h"


Harl::Harl() {
    void (Harl::*tmp[4])(void);
    tmp[0] = &Harl::debug;
    tmp[1] = &Harl::info;
    tmp[2] = &Harl::warning;
    tmp[3] = &Harl::error;
    const char* str[4] = { "DEBUG","INFO","WARNING","ERROR" };
    for (int i = 0; i < 4; i++){
        _levels[i] = str[i];
        fn[i] = tmp[i];
    }
}

void Harl::complain(string level) {
    int i = -1;
    while(++i < 4) {
        if(this->_levels[i] == level){
            (this->*fn[i])();
            break;
        }
    }
}

void Harl::debug() {
    cout << "Debug message" << endl;
}

void Harl::info() {
    cout << "Info message" << endl;
}

void Harl::warning() {
    cout << "Warning message" << endl;
}

void Harl::error() {
    cout << "Error message" << endl;
}