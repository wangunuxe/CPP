#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) { (void)other; }

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

RPN::~RPN() {}

// ── helpers

bool RPN::isOperator(const std::string &token) const
{
    if (token.size() != 1)
        return false;
    char c = token[0];
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isSingleDigit(const std::string &token) const
{
    if (token.size() != 1)
        return false;
    return std::isdigit(static_cast<unsigned char>(token[0]));
}

int RPN::applyOperator(int a, int b, char op) const
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("division by zero");
            return a / b;
        default:
            throw std::runtime_error("unknown operator");
    }
}

// ── public interface

int RPN::evaluate(const std::string &expression) const
{
    std::stack<int> values;
    // iss：把传进来的整个表达式字符串（比如 "8 9 * 9 -"）包装成一个"字符串输入流"，方便像读文件一样一段一段地取
    std::istringstream iss(expression);
    std::string token;

    if (expression.empty())
        throw std::runtime_error("empty expression");
    // iss >> token 的作用是：从流里读出下一个由空白符分隔的片段，存进 token。这个操作会自动跳过多余的空格，也是 >> 运算符对字符串的默认行为
    while (iss >> token)
    {
        if (isSingleDigit(token))
        {
            values.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (values.size() < 2)
                throw std::runtime_error("not enough operands");

            int b = values.top(); values.pop();
            int a = values.top(); values.pop();

            values.push(applyOperator(a, b, token[0]));
        }
        else
        {
            throw std::runtime_error("invalid token => " + token);
        }
    }

    if (values.size() != 1)
        throw std::runtime_error("invalid expression");

    return values.top();
}
