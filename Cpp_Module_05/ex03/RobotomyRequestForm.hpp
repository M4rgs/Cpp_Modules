#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
    
        virtual void executeAction() const;
};

#endif
