#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
public:
    // 用于区分 value 校验失败的具体原因，方便调用方打印对应的错误信息
    enum ValueStatus
    {
        VALUE_OK,
        VALUE_BAD_FORMAT,   // 不是合法数字 / 有多余字符
        VALUE_NEGATIVE,     // 小于 0
        VALUE_TOO_LARGE     // 大于 1000
    };

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void        loadDatabase(const std::string &filename);
    void        processInput(const std::string &filename) const;

private:
    // std::map is sorted by key, making lower_bound lookups efficient
    std::map<std::string, double> _db; // 声明了一个具体的 map 对象

    bool        isValidDate(const std::string &date) const;
    ValueStatus parseValue(const std::string &valueStr, double &out) const;
    double      getRate(const std::string &date) const;
    std::string trimTrailing(const std::string &line) const;
};

#endif
