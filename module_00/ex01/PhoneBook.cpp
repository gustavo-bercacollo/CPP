#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    count, i = 0;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Nick Name: ";
    std::getline(std::cin, input);
    newContact.setNickName(input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    if (count < 8)
        contacts[count++] = newContact;
    else
    {
        contacts[i++] = newContact;
        if (i == 8) i = 0;
    }
    std::cout << "Contact saved!" << std::endl;
}

// void PhoneBook::searchContact()
// {
//     if (count == 0)
//     {
//         std::cout << "No contacts available." << std::endl;
//         return;
//     }
//     std::cout << "| Index | First Name | Last Name  | Nickname   |" << std::endl;
//     std::cout << "-----------------------------------------------" << std::endl;
// }