#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cctype>

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression) const;

private:
    bool isOperator(const std::string &token) const;
    bool isSingleDigit(const std::string &token) const;
    int  applyOperator(int a, int b, char op) const;
};

#endif
