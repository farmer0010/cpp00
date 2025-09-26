#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void){
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);

	std::cout << "["
			  << (now->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << (now -> tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << now ->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0') << now -> tm_hour
			  << std::setw(2) << std::setfill('0') << now ->tm_min
			  << std::setw(2) << std::setfill('0') << now -> tm_sec
			  << "] ";
}

Account::Account(int init_deposit)
{
	Account::_displayTimestamp();
	this -> _accountIndex = Account::_nbAccounts;
	this -> _amount = init_deposit;
	this -> _nbDeposits = 0;
	this -> _nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += init_deposit;

	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this -> _amount << ";"
			  << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this -> _amount << ";"
			  << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	 std::cout << "accounts:" << Account::getNbAccounts() << ";"
              << "total:" << Account::getTotalAmount() << ";"
              << "deposits:" << Account::getNbDeposits() << ";"
              << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this ->_accountIndex << ";"
			  << "p_amount:" << this -> _amount << ";"
			  << "deposit:" << deposit << ";";

			  this -> _amount += deposit;
			  this -> _nbDeposits++;
			  Account::_totalAmount += deposit;
			  Account::_totalNbDeposits++;
	std::cout << "amount:" << this -> _amount << ";"
			  << "nb_deposits:" << this -> _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){

	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << "withdrawal:";
	if(this -> _amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
        return false;
	}
	std::cout << withdrawal << ";";
	this -> _amount -= withdrawal;
	this -> _nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}
