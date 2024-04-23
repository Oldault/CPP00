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
		void	search( void ) const;

	private:

		static const int MAX_CONTACTS = 8;
		Contact contacts[8];
		int	_contactAmount;

		bool getUserInput(const std::string& prompt, std::string& out);
};

#endif