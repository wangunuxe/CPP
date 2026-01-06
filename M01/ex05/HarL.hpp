#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class HarL
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    HarL(void);
    ~HarL(void);

    void complain(std::string level);
};

#endif
