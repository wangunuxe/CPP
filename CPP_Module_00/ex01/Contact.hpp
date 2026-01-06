#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private://data
    std :: string first_name;
    std :: string last_name;
    std :: string nickname;
    std :: string phone_number;
    std :: string darkest_secret;
public://member function and i don't declare the constructor 
	void	setFirstName(const std :: string &first_name);
	void	setLastName(const std :: string &last_name);
	void	setNickname(const std :: string &nickname);
	void	setPhoneNumber(const std :: string &phone_number);
	void	setSecret(const std :: string &darkest_secret);
    std :: string	getFirstName() const;
    std :: string	getLastName() const;
    std :: string	getNickname() const;
    std :: string	getPhoneNumber() const;
    std :: string	getSecret() const;
};
//Inside a class definition, you NEVER write ClassName::
#endif