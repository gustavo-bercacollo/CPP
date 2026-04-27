#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    Intern intern;

    AForm* f1 = intern.makeForm("shrubbery creation", "home");
    AForm* f2 = intern.makeForm("robotomy request", "Bender");
    AForm* f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* f4 = intern.makeForm("unknown form", "X");

    std::cout << "---- testing results ----" << std::endl;

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}