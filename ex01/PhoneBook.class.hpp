#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <array>

class	PhoneBook {
	
	public:

		PhoneBook( void );
		~PhoneBook( void );

	private:

		std::array<Contact, 8> contacts;
};

#endif