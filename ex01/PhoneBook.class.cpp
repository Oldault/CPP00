#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void ) {
	std::cout << "Phone Book is being created" << std::endl;
}

PhoneBook::~PhoneBook ( void ) {
	std::cout << "Phone Book is being deleted" << std::endl;
}
