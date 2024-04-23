
#ifndef	CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

	public:

		Contact( void );
		~Contact( void );

	private:

		int			_phoneNumber;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_darkestSecret;

};

#endif