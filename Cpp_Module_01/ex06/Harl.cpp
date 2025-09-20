#include "Harl.hpp"

Harl::Harl()
{
    return ;
}

void    Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;       
}

void    Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl ;
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl ;
}

void    Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl ;
}

void    Harl::complain(std::string level)
{
    std::string lvls[5] = {"NOTHING", "DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

    for(i = 0; i < 5; i++)
    {
        if (lvls[i] == level)
        {
            this->intLevel = i;
            break;
        }
    }

    switch (this->intLevel)
    {
        case 1:
            debug();
        case 2:
            info();
        case 3:
            warning();
        case 4:
        {
            error();
            break; 
        }
        default:std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

    }
}

Harl::~Harl()
{
    return ;
}