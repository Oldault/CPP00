#include "PhoneBook.class.hpp"
#include <iostream>

int main( void ) {

	PhoneBook phoneBook;

	phoneBook.add("Geroge", "Colormojar", "Gerogie", "9019231", "likes frogs");
	phoneBook.add("Saint", "Main", "Holo", "42", "hates frogs");
	phoneBook.add("", "", "", "21", "");
	phoneBook.add("Pierre", "Rock", "Onix", "360720", "butterman");
	phoneBook.add("Moinamaoulida", "Capabinsogaroll", "bob", "3", "a");

	while (42) {
		if (std::cin.eof()) {
			return 1;
		}
		std::string input;
		std::cout << "[📞] > ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			std::cout << "Adding Contact..." << std::endl;
		}
		else if (input == "SEARCH") {
			std::cout << "Searching for Contacts" << std::endl;
			phoneBook.search();
		}
		else if (input == "EXIT") {
			std::cout << "Exiting Program" << std::endl;
			break ;
		}
		else {
			std::cout << "Invalid Input. Please call: ADD, SEARCH or EXIT" << std::endl;
		}
	}


	return 0;
}