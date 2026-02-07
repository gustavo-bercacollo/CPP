#include "PhoneBook.hpp"
#include "Includes.hpp"
#include "Colors.hpp"

void displayMenu()
{
    PhoneBook phoneBook;
    std::string input;
    while (input != "EXIT")
    {
        std::cout << "\n------------ PHONEBOOK MENU ------------" << std::endl; 
        std::cout << "Type one of the options below:\n" << std::endl;
        std::cout << GREEN << "ADD: " << RESET "save a new contact." << std::endl;
        std::cout << YELLOW "SEARCH: " << RESET "display a specific contact." << std::endl;
        std::cout << RED << "EXIT: " << RESET "ends the program.\n" << std::endl;
    
        std::getline(std::cin, input);
    
        if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
        else if (input == "EXIT")
        {
            std::cout << RED << "Bye! 👋" << RESET << std::endl;
            break;
        }
        else
            std::cout << RED << "Command not fount, try again" << RESET << std::endl;
    }
}

int main(void)
{
  displayMenu();
  return (0);
}