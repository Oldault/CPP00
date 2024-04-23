#include "PhoneBook.class.hpp"
#include "Colors.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook( void ) : _contactAmount(0) {
	std::cout << "Phone Book is being created" << std::endl;
}

PhoneBook::~PhoneBook ( void ) {
	std::cout << "Phone Book is being deleted" << std::endl;
}

bool PhoneBook::getUserInput(const std::string& prompt, std::string& out) {
	if (std::cin.eof()) {
		std::cerr << "Could not complete adding a contact" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << prompt;
	std::getline(std::cin, out);
	if (out.empty()) {
		std::cerr << "Input required, please try again." << std::endl;
		return false;
	}
	return true;
}

bool	PhoneBook::add ( void ) {
	if (_contactAmount >= MAX_CONTACTS) {
		_contactAmount = 0;
	}

	const char* prompts[] = {"First Name: ", "Last Name: ", "Nickname: ", "Phone Number: ", "Darkest Secret: "};
	std::string	input;

	for (int i = 0; i < 5; i++) {
		while (!getUserInput(prompts[i], input)) {
			continue;
		}
		switch (i) {
			case 0: contacts[_contactAmount].setFirstName(input); break; 
			case 1: contacts[_contactAmount].setLastName(input); break; 
			case 2: contacts[_contactAmount].setNickname(input); break; 
			case 3: contacts[_contactAmount].setPhoneNumber(input); break; 
			case 4: contacts[_contactAmount].setSecret(input); break; 
		}
	}

	_contactAmount++;
	return true;
}

void	PhoneBook::search( void ) const {
	std::cout << BBLU("+----------") << BGRN("---------------------------------+") << std::endl;
	std::cout << ITAL(BOLD(BBLU("|Indexes   "))) << ITAL(BOLD(BGRN("|FirstName |LastName  |Nickname  |"))) << std::endl;
	std::cout << BBLU("+----------") << BGRN("+----------+----------+----------+") << std::endl;

	if (_contactAmount == 0) {
		std::cout << "|                                           |" << std::endl;
		std::cout << "| No one is here... Only you, and space...  |" << std::endl;
		std::cout << "|                                           |" << std::endl;
	}

	for (int i = 0; i < _contactAmount ; i++) {
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();

		firstName = firstName.size() > 10 ? firstName.substr(0, 9) + '.' : firstName;
		lastName = lastName.size() > 10 ? lastName.substr(0, 9) + '.' : lastName;
		nickname = nickname.size() > 10 ? nickname.substr(0, 9) + '.' : nickname;

		std::cout << "|" << std::setfill (' ') << std::setw (14);
		std::cout << KMAG << "\x1B[1m" << (i + 1) << RST << "|";
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
