#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <string>

#define MAX_ITER 1000

class	PhoneBook {
	
	public:

		PhoneBook( void );
		~PhoneBook( void );

		bool	add( void );
		void	search( void );

	private:

		static const int MAX_CONTACTS = 8;
		Contact contacts[8];
		int	_totalContacts;
		int	_contactNum;

		bool getUserInput(const std::string& prompt, std::string& out);
		bool getUserIndex(std::string& input);
		void printHeader( void ) const;
		void printContact(const Contact& contact, int index) const;
		void handleUserInput( void );
};

#endif