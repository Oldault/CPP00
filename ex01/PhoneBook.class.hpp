#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <string>

class	PhoneBook {
	
	public:

		PhoneBook( void );
		~PhoneBook( void );

		bool	add(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNumber, const std::string& darkestSecret);
		void	search( void );

	private:

		int		_contactAmount;
		Contact contacts[8];
};

#endif