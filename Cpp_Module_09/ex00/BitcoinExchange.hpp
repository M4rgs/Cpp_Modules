#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>


class BitcoinExchange{
    private:
        std::map<std::string, float> map;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void checkInput(const std::string file);
        void checkConetnt(std::string date, float value);

        class FileNotExist : public std::exception{
            public:
                const char* what()  const throw();
        };
        class WrongContent : public std::exception{
            public:
                const char* what()  const throw();
        };
        class InvalidValue : public std::exception{
            public:
                const char* what()  const throw();
        };

};

#endif