#include "Account.hpp"
#include "Colors.h"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	: _amount(initial_deposit) ,_nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << KBLU << _accountIndex << RST << ";" << "amount:" << KBLU << _amount << RST << ";created\n";
}

Account::~Account ( void ) {
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << KBLU << _accountIndex << RST << ";" << "amount:" << KBLU << _amount << RST << ";closed\n";

}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "acounts:" << KBLU << _nbAccounts << RST << ";total:" << KBLU << _totalAmount << RST << ";deposits:" << KBLU << _totalNbDeposits << RST << ";widthdrawals:" << KBLU << _totalNbWithdrawals << RST << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << KBLU << _accountIndex << RST << ";p_amount:" << KBLU << (_amount - deposit) << RST << ";deposit:" << KBLU << deposit << RST << ";amount:" << KBLU << _amount << RST << ";nb_deposits:" << KBLU << _nbDeposits << RST << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout<< "index:" << KBLU << _accountIndex << RST << ";" << "p_amount:" << KBLU << _amount << RST << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "index:" << KBLU << _accountIndex << RST << ";p_amount:" << KBLU << (_amount + withdrawal) << RST << ";withdrawal:" << KBLU << withdrawal << RST << ";amount:" << KBLU << _amount << RST << ";nb_withdrawals:" << KBLU << _nbWithdrawals << RST << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << KBLU << _accountIndex << RST << ";amount:" << KBLU << _amount << RST << ";deposits:" << KBLU << _nbDeposits << RST << ";withdrawals:" << KBLU << _nbWithdrawals << RST << std::endl;
}

void	Account::_displayTimestamp ( void ) {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[" << (1900 + ltm->tm_year) << std::setw(2) << std::setfill('0') << (1 + ltm->tm_mon) << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_" << std::setw(2) << std::setfill('0') << ltm->tm_hour << std::setw(2) << std::setfill('0') << ltm->tm_min << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}