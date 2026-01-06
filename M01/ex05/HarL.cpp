#include "HarL.hpp"

HarL::HarL(void){}

HarL::~HarL(void){}

void    HarL::debug(void)
{
    std::cout << "[ DEBUG ]\n"
            << "I love having extra bacon for my "
            << "7XL-double-cheese-triple-pickle-specialketchup burger.\n"
            << std::endl;
}

void HarL::info(void)
{
    std::cout
        << "[ INFO ]\n"
        << "I cannot believe adding extra bacon costs more money.\n"
        << std::endl;
}

void HarL::warning(void)
{
    std::cout
        << "[ WARNING ]\n"
        << "I think I deserve to have some extra bacon for free.\n"
        << std::endl;
}

void HarL::error(void)
{
    std::cout
        << "[ ERROR ]\n"
        << "This is unacceptable! I want to speak to the manager now.\n"
        << std::endl;
}

void HarL::complain(std::string level)
{
    std::string levels[4] = 
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    void (HarL::*functions[4])(void) = 
    {
        &HarL::debug,
        &HarL::info,
        &HarL::warning,
        &HarL::error
    };//functions is an array of 4 pointers to member functions of HarL that take no parameters and return void.
    //void (*funcs[4])(int):array of 4 pointers to functions taking int and returning void
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }
}



// //*** The pointer to normal function and The pointer to member function
// //1. Pointer to normal function:
// char* f(int x);
// char*(*ptr)(int) = f; //**the f can decay into &f
// //we can call:
// ptr(42); //correct
// (*ptr)(42); //correct, put the *ptr in brakets

// //2. Pointer to member function:
// class HarL {
// public:
//     char* f(int x);
// };
// char* HarL::f(int x);
// char* (HarL::*ptr)(int) = &HarL::f; //**the member function HarL::f can not decay to pointer 
// HarL::ptr(42) // x
// (object.*ptr)(42)// correct, put the object.*ptr in brackets