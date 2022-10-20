#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

using std::cout;
using std::endl;

Account::Account(int initial_deposit) {
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _nbAccounts++ << ";ammount:" << initial_deposit << ";created" << endl;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << "; total : " << _totalAmount << "; deposits : " << _totalNbDeposits
              << "; withdrawals:" << _totalNbWithdrawals << endl;
}

void Account::_displayTimestamp() {
    std::time_t time_now = std::time(NULL);

    tm time = *localtime(&time_now);
    cout << std::setfill('0') << "[" <<
         std::setw(2) << time_now.tm_year + 1900 <<
         std::setw(2) << time.tm_mon <<
         std::setw(2) << time.tm_mday << "_" <<
         std::setw(2) << time.tm_hour <<
         std::setw(2) << time.tm_min <<
         std::setw(2) << time.tm_sec << "]";

    //cout << "[19920104_091532] ";
}

void Account::displayStatus() const {
    _displayTimestamp();
    cout << "index:" << _accountIndex << "; amount : " << _amount << "; deposits : " << _nbDeposits << "; withdrawals:"
         << _nbWithdrawals << endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    cout << "index : " << _accountIndex << "; p_amount : " << _amount - deposit << "; deposit : " << deposit
         << "; amount : " << _amount << "; nb_deposits:" << _nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (withdrawal > checkAmount()) {
        cout << "index : " << _accountIndex << "; p_amount : " << _amount << "; withdrawal:refused" << endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= _amount;
    cout << "index : " << _accountIndex << "; p_amount : " << _amount - withdrawal << "; withdrawal : " << withdrawal
         << "; amount : " << _amount << "; nb_withdrawals:" << _nbWithdrawals << endl;
    return true;
}

int Account::checkAmount() const {
    return _amount;
}

Account::~Account() {
    _displayTimestamp();
    cout << "index : " << _accountIndex << "; amount : " << _amount << ";closed" << endl;
}