#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
    private:
        std::string         name;
    public:
        DiamondTrap();
        DiamondTrap(std::string _name);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI();
};
