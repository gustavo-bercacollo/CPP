#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 40);
        Bureaucrat low("Low", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- SIGN FORMS ---\n" << std::endl;

        low.signForm(shrub);
        mid.signForm(robo);
        boss.signForm(pardon);

        std::cout << "\n--- EXECUTION TESTS ---\n" << std::endl;

        low.executeForm(shrub);
        mid.executeForm(robo); 
        boss.executeForm(pardon); 

        std::cout << "\n--- FORCE ERROR TEST ---\n" << std::endl;

        low.executeForm(pardon); 

    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
