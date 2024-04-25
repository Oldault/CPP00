#include "PhoneBook.class.hpp"
#include "Colors.h"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook( void ) :  _totalContacts(0), _contactNum(0) {
	return ;
}

PhoneBook::~PhoneBook ( void ) {
	return ;
}

bool PhoneBook::getUserInput(const std::string& prompt, std::string& out) {
	if (std::cin.eof()) {
		std::cerr << ITAL(BRED("Could not complete adding a contact")) << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "\x1B[1m" << KMAG << prompt << RST << "\t";
	std::getline(std::cin, out);
	if (out.empty()) {
		std::cerr << ITAL(BRED("Input required, please try again.")) << std::endl;
		return false;
	}
	return true;
}

bool	PhoneBook::add ( void ) {
	if (_contactNum >= MAX_CONTACTS) {
		_contactNum = 0;
	}

	const char* prompts[] = {"First Name: ", "Last Name: ", "Nickname: ", "Phone Number: ", "Darkest Secret:"};
	std::string	input;

	std::cout << std::endl;
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
	std::cout << std::endl;
	std::cout << ITAL(BOLD("\t   * User was added to contacts! *\n\n"));

	_contactNum++;
	_totalContacts++;
	return true;
}

unsigned int stringToUnsignedInt(const std::string& str) {
    std::istringstream iss(str);
    unsigned int number;
    if (!(iss >> number)) {
        return -1;
    }
    return number;
}

bool PhoneBook::getUserIndex(std::string& input) {
	if (std::cin.eof()) {
		std::cerr << "Could not complete fetching contact" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << BOLD(FMAG("Index of the entry to display (Example; 1, 2 or 3).\nWrite ")) << ITAL(FRED("LEAVE")) << BOLD(FMAG(" to exit search.")) << std::endl;
	std::cout << FYEL("\tIndex > ");
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cerr << ITAL(BRED("Input required, please try again.")) << std::endl;
		return false;
	}
	if (input == "LEAVE") {
		return true;
	}
	uint16_t result = stringToUnsignedInt(input);
	if (result < 1 || result > _totalContacts) {
		std::cerr << ITAL(BRED("No contact at such index. Please try again")) << std::endl;
		return false;
	}
	return true;
}

void	PhoneBook::printHeader ( void ) const {
	std::cout << "\n\t" << BBLU("+----------") << BGRN("---------------------------------+") << std::endl;
	std::cout << "\t" << ITAL(BOLD(BBLU("|Indexes   "))) << ITAL(BOLD(BGRN("|FirstName |LastName  |Nickname  |"))) << std::endl;
	std::cout << "\t" << BBLU("+----------") << BGRN("+----------+----------+----------+") << std::endl;

	if (_contactNum == 0) {
		std::cout << "\t|                                           |\n";
		std::cout << "\t| No one is here... Only you, and space...  |\n";
		std::cout << "\t|                                           |\n";
	}
}

std::string formatName(const std::string& name) {
	uint16_t MaxNameLength = 10;
    return name.size() > MaxNameLength ? name.substr(0, MaxNameLength - 1) + '.' : name;
}

void	PhoneBook::printContact(const Contact& contact, int index) const {
	std::string firstName = formatName(contact.getFirstName());
	std::string lastName = formatName(contact.getLastName());
	std::string nickname = formatName(contact.getNickname());

	std::cout << "\t|" << std::setfill(' ') << std::setw(14) << KMAG << "\x1B[1m" << (index + 1) << RST << "|";
    std::cout << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickname << "|\n";
}

void	PhoneBook::handleUserInput( void ) {
	std::string	input;

	while (!getUserIndex(input)) {
		continue;
	}
	if (input == "LEAVE") {
		std::cout << std::endl;
		return ;
	}
	uint16_t index = (stringToUnsignedInt(input) - 1);
	std::cout << std::endl;
	std::cout << BOLD("\tFirst name: ") << "\x1B[3m" << contacts[index].getFirstName() << RST << std::endl;
	std::cout << BOLD("\tLast name: ") << "\x1B[3m" << contacts[index].getLastName() << RST << std::endl;
	std::cout << BOLD("\tNickname: ") << "\x1B[3m" << contacts[index].getNickname() << RST << std::endl;
	std::cout << BOLD("\tPhone Number: ") << "\x1B[3m" << contacts[index].getPhoneNumber() << RST << std::endl;
	std::cout << BOLD("\tDarkest Secret: ") << "\x1B[3m" << contacts[index].getSecret() << RST << "\n\n";
}

void	PhoneBook::search( void ) {
	printHeader();
	for (int i = 0; i < _totalContacts && i < MAX_CONTACTS ; i++) {
		printContact(contacts[i], i);
	}
	std::cout << "\t+-------------------------------------------+\n\n";
	handleUserInput();
}
