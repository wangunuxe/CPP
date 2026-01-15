#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

void	Contact :: setFirstName(const std :: string &fn)
{
	first_name = fn;
}

void	Contact :: setLastName(const std :: string &ln)
{
	last_name = ln;
}

void	Contact :: setNickname(const std :: string &nn)
{
	nickname = nn;
}

void	Contact :: setPhoneNumber(const std :: string &pn)
{
	phone_number = pn;
}

void	Contact :: setSecret(const std :: string &s)
{
	darkest_secret = s;
}

std :: string Contact :: getFirstName() const
{
	return first_name;
}

std :: string Contact :: getLastName() const
{
	return last_name;
}

std :: string Contact :: getNickname() const
{
	return nickname;
}

std :: string Contact :: getPhoneNumber() const
{
	return phone_number;
}

std :: string Contact :: getSecret() const
{
	return darkest_secret;
}
