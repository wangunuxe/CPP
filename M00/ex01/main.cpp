#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
//THe main is only responsible for reading commands and delegating work to the PhoneBook object.
//The PhoneBook object lives only inside main
int	main()
{
	std :: string	command;
	Phonebook pb;

	while (true)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, command))
			break;//Ctrl + D

		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break;
	}
	return 0;
}