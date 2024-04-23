#include "Contact.class.hpp"
#include <iostream>

Contact::Contact( void ) {
	std::cout << "Contact is being Created" << std::endl;
}

Contact::~Contact( void ) {
	std::cout << "Contact is being Deleted" << std::endl;
}
