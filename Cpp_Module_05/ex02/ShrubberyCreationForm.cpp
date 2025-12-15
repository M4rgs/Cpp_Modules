#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream ofile((target + "_shrubbery").c_str());
    if (!ofile)
    {
        std::cerr << "Error: Could not open the file !" << std::endl;
        return ;
    }
    ofile << 
        "       /\\\n"
        "      /**\\\n"
        "     /****\\\n"
        "    /******\\\n"
        "   /********\\\n"
        "      ||||\n"
        "      ||||\n";

    ofile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}