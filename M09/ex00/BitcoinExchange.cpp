#include "BitcoinExchange.hpp"
//OCF  Orthodox Canonical Form

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// ── helpers 

// Remove trailing '\r' or whitespace (handles CRLF-formatted input files)
std::string BitcoinExchange::trimTrailing(const std::string &line) const
{
    std::string result = line;
    while (!result.empty() &&
           (result[result.size() - 1] == '\r' ||
            result[result.size() - 1] == '\n' ||
            result[result.size() - 1] == ' '  ||
            result[result.size() - 1] == '\t'))
    {
        result.erase(result.size() - 1);
    }
    return result;
}

// Validate "YYYY-MM-DD" and check calendar ranges
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7) continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year  = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day   = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // Months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    // February
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && day > (leap ? 29 : 28))
        return false;

    return true;
}

// Parse value and classify the result. Does NOT print anything itself:
// the caller decides which message fits, based on the returned status.
BitcoinExchange::ValueStatus BitcoinExchange::parseValue(const std::string &valueStr, double &out) const
{
    if (valueStr.empty())
        return VALUE_BAD_FORMAT;

    std::istringstream iss(valueStr);
    double val;
    if (!(iss >> val))
        return VALUE_BAD_FORMAT;

    std::string leftover;
    if (iss >> leftover)
        return VALUE_BAD_FORMAT;   // trailing garbage, e.g. "1.2.3" or "12abc"

    if (val < 0.0)
        return VALUE_NEGATIVE;
    if (val > 1000.0)
        return VALUE_TOO_LARGE;

    out = val;
    return VALUE_OK;
}

// Find closest date <= requested date using lower_bound
double BitcoinExchange::getRate(const std::string &date) const
{
    // lower_bound 是 std::map 自带的一个成员函数 : 返回指向"第一个不小于 key 的元素"的迭代器
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

    if (it == _db.end() || it->first != date)
    {
        // No exact match: step back to the nearest earlier date
        if (it == _db.begin())
            throw std::runtime_error("no data available for date: " + date);
        --it;
    }
    return it->second;
}

// ── public interface 
//读取 database（data.csv），建立查找表: 把文件内容搬进内存里的 _db 这个 map，方便之后快速查找
void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // skip header "date,exchange_rate"

    while (std::getline(file, line))
    {
        line = trimTrailing(line);
        if (line.empty()) continue;

        std::size_t comma = line.find(',');
        if (comma == std::string::npos) continue;

        std::string date     = line.substr(0, comma);
        std::string rateStr  = line.substr(comma + 1);

        double rate = atof(rateStr.c_str());
        _db[date] = rate;
    }
}

// 读取 input.txt，逐行校验 + 查表 + 计算 + 输出
void BitcoinExchange::processInput(const std::string &filename) const
{
    // read input
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header "date | value"

    while (std::getline(file, line))
    {
        // 逐行校验
        line = trimTrailing(line);
        if (line.empty()) continue;

        // Expect format: "date | value"
        std::size_t pipe = line.find(" | ");
        if (pipe == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date     = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 3);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value = 0.0;
        ValueStatus status = parseValue(valueStr, value);

        if (status == VALUE_BAD_FORMAT)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (status == VALUE_NEGATIVE)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (status == VALUE_TOO_LARGE)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        // 
        try
        {
            double rate   = getRate(date); //查表
            double result = value * rate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
