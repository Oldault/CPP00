#include "PhoneBook.class.hpp"

int main( void ) {
	PhoneBook phoneBook;

	phoneBook.add("George", "Colorado", "Gerogie", "9019231", "likes frogs");
	phoneBook.add("Saint", "Main", "Holo", "42", "hates frogs");
	phoneBook.add("", "", "", "21", "");
	phoneBook.add("Pierre", "Rock", "Onix", "360720", "butterman");

	phoneBook.search();
}