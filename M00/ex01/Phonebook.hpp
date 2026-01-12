#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <sstream>

class Phonebook
{
private :
	Contact contacts[8];
	int	count;//The present number of concacts
	int	next_index;// The next index of contact to fill or overwrite
public:
	Phonebook();// If a class contains primitive types (int, char, etc.), we should declare a constructor to initialize them. 
	void	addContact();
	void	searchContact();

};

#endif