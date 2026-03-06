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


void BitcoinExchange::getCsvContent(const std::string file)
{
    std::ifstream input(file.c_str());
    if (!input)
        throw FileNotExist();
    std::string line;
    std::getline(input, line);
    if (line != "date,exchange_rate")
    {
        input.close();
        throw NotValidCsv();
    }
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string csv_date; 
        std::getline(ss, csv_date, ',');
        float csv_value; 
        ss >> csv_value;
        this->map[csv_date] = csv_value;
    }
    input.close();
}

bool BitcoinExchange::checkValidDate(std::string date)
{
    int i = 0, count_tir = 0, count_dates = 0;
    while (date[i])
    {
        while (date[i] && date[i] == '-')
        {
            i++;
            count_tir++;
        }
        if (date[i])
            count_dates++;
        while (date[i] && date[i] != '-')
        {
            if (!isdigit(date[i]))
                return false;
            i++;
        }
    }
    if (count_tir == 2 && count_dates == 3)
        return (true);
    return false;
}

bool BitcoinExchange::checkValidDays(int year, int month, int day)
{
    if (day < 1 || month < 1 || day > 31 || month > 12)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2)
    {
        if ((leap && day > 29) || (!leap && day > 28))
            return false;
    }
    return (true);
}

void BitcoinExchange::startComparing(std::string date, float value)
{
    std::map<std::string, float>::const_iterator iterator = this->map.lower_bound(date);
    if (iterator != this->map.end())
    {
        if (date != iterator->first)
            --iterator;
        float val = iterator->second;
        std::cout << iterator->first << " => " <<  value * val << std::endl;
    }
    else
        std::cout << "Not Found !" << std::endl;
}

void BitcoinExchange::checkConetnt(std::string date, float value)
{

    if (value < 0 || value > 1000)
        throw InvalidValue();
    if (!checkValidDate(date))
        throw InvalidDate();

    int year, month, day;
    std::string temp = date;
    for (size_t i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '-')
            temp[i] = ' ';
    }
    std::stringstream ss(temp);
    ss >> year >> month >> day;
    if (!checkValidDays(year, month, day))
        throw InvalidDate();
    startComparing(date, value);

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


const char* BitcoinExchange::NotValidCsv::what() const throw()
{
    return "Invalid Csv File !";
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

const char* BitcoinExchange::InvalidDate::what() const throw()
{
    return "Invalid Date Detected !";
}


BitcoinExchange::~BitcoinExchange()
{

}