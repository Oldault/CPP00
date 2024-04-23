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
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();

		firstName = firstName.size() > 10 ? firstName.substr(0, 9) + '.' : firstName;
		lastName = lastName.size() > 10 ? lastName.substr(0, 9) + '.' : lastName;
		nickname = nickname.size() > 10 ? nickname.substr(0, 9) + '.' : nickname;

		std::cout << "|" << std::setfill (' ') << std::setw (10);
		std::cout << (i + 1) << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << firstName << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << lastName << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << nickname << "|";
		std::cout << std::endl;
	}
	std::cout << "+-------------------------------------------+" << std::endl;
}
