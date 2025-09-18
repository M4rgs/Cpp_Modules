#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class   Harl{
    private:
        void    info(void);
        void    debug(void);
        void    warning(void);
        void    error(void);
        int     intLevel;
    public:
        Harl(void);

        void complain(std::string level);

        ~Harl(void);
};

#endif