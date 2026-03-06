#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    (void)other;
    return *this;
}

void BitcoinExchange::checkConetnt(std::string date, float value)
{

    if (value < 0 || value > 1000)
        throw InvalidValue();
    (void)date;

}
void BitcoinExchange::checkInput(const std::string file)
{
    std::ifstream s(file.c_str());
    if (!s.is_open() || s.eof())
        throw FileNotExist();
    std::string line;
    std::getline(s, line);
    if (line != "date | value")
        throw WrongContent();
    line = "";
    std::string date;
    float value;
    while (std::getline(s, line))
    {
        std::stringstream ss(line);
        std::getline(ss, date, '|');
        boost::trim(date);
        ss >> value;
        boost::trim(date);
        if (ss.fail())
            throw InvalidValue();
        else
            checkConetnt(date, value);
        line.clear();
    }
    
}




const char* BitcoinExchange::FileNotExist::what() const throw()
{
    return "File Not Exist !";
}

const char* BitcoinExchange::WrongContent::what() const throw()
{
    return "Wrong File Content !";
}

const char* BitcoinExchange::InvalidValue::what() const throw()
{
    return "Invalid Value Detected !";
}

BitcoinExchange::~BitcoinExchange()
{

}