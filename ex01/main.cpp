#include "PhoneBook.class.hpp"
#include "Colors.h"
#include <iostream>

void printArt() {
    std::cout << "\n\t         _______________\n";
    std::cout << "\t        /               \\\n";
    std::cout << "\t       |   .---------.   |@\n";
    std::cout << "\t       '---' .-----. '---'@\n";
    std::cout << "\t         .' /6 5_4 3\\ '.  @\n";
    std::cout << "\t         | |7 /...\\ 2| |  @\n";
    std::cout << "\t         | |8 \\___/ 1| |  @\n";
    std::cout << "\t         |  \\_9_0_)\\/  |  @@\n";
    std::cout << "\t      /==|_____________|@@@@\n";
    std::cout << "\t      H-------------------@@\n";
    std::cout << "\t      H   )  ||   ||  (   @@\n";
    std::cout << "\t      H  /   ||   ||   \\   @\n";
    std::cout << "\t      H |----''---''----|\n";
    std::cout << "\t     =/ |_______________|\n\n";
	std::cout << ITAL(BOLD("\t   * Welcome to this Phonebook! *\n\n"));
	std::cout << KGRN << UNDL("\t[ADD]") << ITAL(" : Will add a contact.\n") << RST;
	std::cout << KBLU << UNDL("\t[SEARCH]") << ITAL(" : Will fetch a users data.\n") << RST;
	std::cout << KRED << UNDL("\t[EXIT]") << ITAL(" : Will terminate the program.\n\n") << RST;
}

int main( void ) {

	PhoneBook phoneBook;
	std::string input;

	uint16_t i = 0;
	printArt();
	while (true && i++ < MAX_ITER) {
		if (std::cin.eof()) {
			break ;
		}
		std::cout << "[📞] > ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			phoneBook.add();
		}
		else if (input == "SEARCH") {
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
