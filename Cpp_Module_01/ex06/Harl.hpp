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
        Harl(std::string level);

        void complain();

        ~Harl(void);
};