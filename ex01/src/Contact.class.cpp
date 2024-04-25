#include "Contact.class.hpp"
#include <iostream>

bool	Contact::setFirstName(const std::string& firstName) {
	if (firstName.empty()) {
		return false;
	}
	_firstName = firstName;
	return true;
}

bool	Contact::setLastName(const std::string& lastName) {
	if (lastName.empty()) {
		return false;
	}
	_lastName = lastName;
	return true;
}

bool	Contact::setNickname(const std::string& nickname) {
	if (nickname.empty()) {
		return false;
	}
	_nickname = nickname;
	return true;
}

bool	Contact::setPhoneNumber(const std::string& phoneNumber) {
	if (phoneNumber.empty()) {
		return false;
	}
	_phoneNumber = phoneNumber;
	return true;
}

bool	Contact::setSecret(const std::string& darkestSecret) {
	if (darkestSecret.empty()) {
		return false;
	}
	_darkestSecret = darkestSecret;
	return true;
}

const std::string&	Contact::getFirstName( void ) const {
	return _firstName;
}

const std::string&	Contact::getLastName( void ) const {
	return _lastName;
}

const std::string&	Contact::getNickname( void ) const {
	return _nickname;
}

const std::string&	Contact::getPhoneNumber( void ) const {
	return _phoneNumber;
}

const std::string&	Contact::getSecret( void ) const {
	return _darkestSecret;
}