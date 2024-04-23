#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void ) : _contactAmount(0) {
	std::cout << "Phone Book is being created" << std::endl;
}

PhoneBook::~PhoneBook ( void ) {
	std::cout << "Phone Book is being deleted" << std::endl;
}

bool	PhoneBook::add (const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNumber, const std::string& darkestSecret) {
	
	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() ||darkestSecret.empty()) {
		std::cerr << "Empty field in assignment was detected 🗃️" << std::endl;
		return false;
	}
	if (_contactAmount >= 8) {
		_contactAmount = 0;
	}

	contacts[_contactAmount].setFirstName(firstName);
	contacts[_contactAmount].setLastName(lastName);
	contacts[_contactAmount].setNickname(nickname);
	contacts[_contactAmount].setPhoneNumber(phoneNumber);
	contacts[_contactAmount].setSecret(darkestSecret);

	_contactAmount++;

	return true;
}

void	PhoneBook::search( void ) {
	std::cout << "+-------------------------------------------+" << std::endl;
	for (int i = 0; i < _contactAmount ; i++) {
		std::cout << "|" << std::setfill (' ') << std::setw (10);
		std::cout << (i + 1) << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << contacts[i].getFirstName() << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << contacts[i].getLastName() << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << contacts[i].getNickname() << "|";
		std::cout << std::endl;
	}
	std::cout << "+-------------------------------------------+" << std::endl;
}
