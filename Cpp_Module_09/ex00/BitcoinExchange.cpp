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
    if (this != &other)
        this->map = other.map;
    return *this;
}

void BitcoinExchange::spaceTrim(std::string &date)
{
    int start = 0;
    int end = date.size() - 1;

    while (start <= end && date[start] == ' ')
        start++;

    while (end >= start && date[end] == ' ')
        end--;

    date = date.substr(start, end - start + 1);
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
        if (ss.fail())
            throw NotValidCsv();
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
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    int y = 1900 + ltm->tm_year;
    if (year > y)
        return false;
    if (day < 1 || month < 1 || day > 31 || month > 12)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    bool starting_btc = (year < 2009 || (year == 2009 && (month == 1 && day < 2)));
    if (starting_btc)
        return false;
    if (month == 2)
    {
        if ((leap && day > 29) || (!leap && day > 28))
            return false;
    }
    return (true);
}

void BitcoinExchange::startComparing(const std::string date, float value)
{
    std::map<std::string, float>::const_iterator it = this->map.upper_bound(date);
    if (it == this->map.begin())
    {
        std::cerr << "No earlier date found!" << std::endl;
        return;
    }
    --it;
    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::checkConetnt(std::string date, float value)
{

    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }

    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    if (!checkValidDate(date))
    {
        std::cerr << "Error: bad input=> " << date << std::endl;
        return;
    }

    int year, month, day;
    std::string temp = date;
    char dash;
    std::stringstream ss(temp);
    ss >> year >> dash >>  month >> dash >> day;
    if (!checkValidDays(year, month, day))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    startComparing(date, value);

}
void BitcoinExchange::checkInput(const std::string file)
{
    std::ifstream s(file.c_str());
    if (!s.is_open())
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
        spaceTrim(date);

        std::string valstr;
        std::getline(ss, valstr);
        spaceTrim(valstr);

        std::stringstream val(valstr);
        val >> value;

        if (val.fail() || !val.eof())
            std::cerr << "Error: bad input => " << line << std::endl;
        else
            checkConetnt(date, value);
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

BitcoinExchange::~BitcoinExchange()
{

}