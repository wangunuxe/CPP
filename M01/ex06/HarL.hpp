#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstring>

class HarL
{
public:
	HarL();
	~HarL();
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
