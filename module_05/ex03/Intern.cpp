#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }


static AForm* createShrub(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobot(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {

    struct FormPair {
        std::string name;
        AForm* (*creator)(const std::string&);
    };

    FormPair forms[] = {
        {"shrubbery creation", createShrub},
        {"robotomy request", createRobot},
        {"presidential pardon", createPardon}
    };

    for (int i = 0; i < 3; i++) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }

    std::cout << "Intern: form '" << formName << "' does not exist!" << std::endl;
    return NULL;
}
