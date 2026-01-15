# include "Phonebook.hpp"
# include <cctype>

Phonebook :: Phonebook()//The constuctor do NOT have a reture type, not even "void"
{
	count = 0;
	next_index = 0;
}
Phonebook::~Phonebook() {};

void	Phonebook :: addContact()//Normal member function need a return type
{
	std :: string	input;

	input = "";
	while (input.empty())
	{
		std :: cout << "Enter the first name : ";
		std :: getline(std :: cin, input);
	}
	contacts[next_index].setFirstName(input);

	input = "";
	while (input.empty())
	{
		std :: cout << "Enter the last name : ";
		std :: getline(std :: cin, input);
	}
	contacts[next_index].setLastName(input);

	input = "";
	while (input.empty())
	{
		std :: cout << "Enter the nickname : ";
		std :: getline(std :: cin, input);
	}
	contacts[next_index].setNickname(input);

	input = "";
	while (input.empty())
	{
		std :: cout << "Enter the phone number : ";
		std :: getline(std :: cin, input);
	}
	contacts[next_index].setPhoneNumber(input);
	input = "";
	while (input.empty())
	{
		std :: cout << "Enter the darkest secret : ";
		std :: getline(std :: cin, input);
	}
	contacts[next_index].setSecret(input);

	if (count < 8)
		count++;
	next_index = (next_index + 1) % 8;//This line implements the “replace the oldest contact” rule
}

std :: string truncate_string(std :: string s)
{
	if (s.length() > 10)
		s = s.substr(0, 9) + '.';//truncate the string
	return s;
}

void	Phonebook :: searchContact()
{
	int	i;
	std :: string input;
	int	n;

	if (count == 0)
		std :: cout << "This is a empty phonebook" << std :: endl;
	std :: cout << "|" << std :: setw(10) << "index"
	<< "|" << std :: setw(10) << "first name"
	<< "|" << std :: setw(10) << "last name"
	<< "|" << std :: setw(10) << "nickname"	
	<< std :: endl;
	i = 0;
	while (i < count)
	{
		std :: cout << "|" << std :: setw(10) << i
		<< "|" << std :: setw(10) << truncate_string(contacts[i].getFirstName())
		<< "|" << std :: setw(10) << truncate_string(contacts[i].getLastName())
		<< "|" << std :: setw(10) << truncate_string(contacts[i].getNickname())
		<< std :: endl;
		i++;
	}
	//display the information of a contact
	n = -1;
	while (n < 0 || n >= count)
	{
		std :: cout << "Enter the index of contact : ";
		std :: getline(std :: cin, input);
		std :: stringstream ss(input);
		ss >> n;
	}
	std :: cout << "First name : " << truncate_string(contacts[n].getFirstName()) << std :: endl;
	std :: cout << "Last name : " << truncate_string(contacts[n].getLastName()) << std :: endl;
	std :: cout << "Nickname : " << truncate_string(contacts[n].getNickname()) << std :: endl;
	std :: cout << "Phone number : " << truncate_string(contacts[n].getPhoneNumber()) << std :: endl;
	std :: cout << "Darkest secret : " << truncate_string(contacts[n].getSecret()) << std :: endl;
}