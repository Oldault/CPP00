#include "PhoneBook.class.hpp"
#include "Colors.h"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook( void ) :  _totalContacts(0), _contactNum(0) {
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
	if (_contactNum >= MAX_CONTACTS) {
		_contactNum = 0;
	}

	const char* prompts[] = {"First Name: ", "Last Name: ", "Nickname: ", "Phone Number: ", "Darkest Secret: "};
	std::string	input;

	for (int i = 0; i < 5; i++) {
		while (!getUserInput(prompts[i], input)) {
			continue;
		}
		switch (i) {
			case 0: contacts[_contactNum].setFirstName(input); break; 
			case 1: contacts[_contactNum].setLastName(input); break; 
			case 2: contacts[_contactNum].setNickname(input); break; 
			case 3: contacts[_contactNum].setPhoneNumber(input); break; 
			case 4: contacts[_contactNum].setSecret(input); break; 
		}
	}

	_contactNum++;
	_totalContacts++;
	return true;
}

unsigned int stringToUnsignedInt(const std::string& str) {
    std::istringstream iss(str);
    unsigned int number;
    if (!(iss >> number)) {
        std::cerr << "Conversion failed!" << std::endl;
        return -1;
    }
    return number;
}

bool PhoneBook::getUserIndex(std::string& input) {
	if (std::cin.eof()) {
		std::cerr << "Could not complete fetching contact" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Index of the entry to display: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cerr << "Input required, please try again." << std::endl;
		return false;
	}
	uint16_t result = stringToUnsignedInt(input);
	if (result < 1 || result > _totalContacts) {
		std::cerr << "No contact at such index. Please try again" << std::endl;
		return false;
	}
	return true;
}

void	PhoneBook::search( void ) {
	std::cout << BBLU("+----------") << BGRN("---------------------------------+") << std::endl;
	std::cout << ITAL(BOLD(BBLU("|Indexes   "))) << ITAL(BOLD(BGRN("|FirstName |LastName  |Nickname  |"))) << std::endl;
	std::cout << BBLU("+----------") << BGRN("+----------+----------+----------+") << std::endl;

	if (_contactNum == 0) {
		std::cout << "|                                           |" << std::endl;
		std::cout << "| No one is here... Only you, and space...  |" << std::endl;
		std::cout << "|                                           |" << std::endl;
	}

	for (int i = 0; i < _totalContacts && i < MAX_CONTACTS ; i++) {
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();

		firstName = firstName.size() > 10 ? firstName.substr(0, 9) + '.' : firstName;
		lastName = lastName.size() > 10 ? lastName.substr(0, 9) + '.' : lastName;
		nickname = nickname.size() > 10 ? nickname.substr(0, 9) + '.' : nickname;

		std::cout << "|" << std::setfill (' ') << std::setw (14);
		std::cout << KMAG << "\x1B[1m" << (i + 1) << RST << "|";
		for (int j = 0; j < 3 ; j++) {
			std::cout << std::setfill (' ') << std::setw (10);
			switch (j) {
				case 0: std::cout << firstName << "|"; break;
				case 1: std::cout << lastName << "|"; break;
				case 2: std::cout << nickname << "|" << std::endl; break;
			}
		}
	}
	std::cout << "+-------------------------------------------+" << std::endl;

	std::string	input;
	while (!getUserIndex(input)) {
		continue;
	}
	uint16_t index = (stringToUnsignedInt(input) - 1);
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
}
