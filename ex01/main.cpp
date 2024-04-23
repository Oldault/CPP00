#include "PhoneBook.class.hpp"
#include <iostream>

int main( void ) {

	PhoneBook phoneBook;
	std::string input;

	uint16_t i = 0;
	while (42 && i++ < MAX_ITER) {
		if (std::cin.eof()) {
			break ;
		}
		std::cout << "[📞] > ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			std::cout << "Adding Contact..." << std::endl;
			phoneBook.add();
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