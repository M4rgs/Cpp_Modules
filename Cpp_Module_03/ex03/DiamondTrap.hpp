#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
    private:
        std::string         name;
    public:
        DiamondTrap();
        DiamondTrap(std::string _name);
        DiamondTrap(const DiamondTrap &_copy);
        DiamondTrap& operator=(const DiamondTrap& dt);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI();
};
