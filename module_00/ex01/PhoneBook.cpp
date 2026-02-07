#include "PhoneBook.hpp"
#include "Includes.hpp"
#include "Colors.hpp"

PhoneBook::PhoneBook()
{
    count = 0;
    i = 0;
}
static std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 10) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::displayContact(int index)
{
    Contact c = contacts[index];

    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
    std::cout << std::endl;
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
    std::cout << GREEN << "Contact saved! ✅" << RESET << std::endl;
}

void PhoneBook::askContactIndexAndDisplay()
{
    while (true)
    {
        std::cout << "--> To more details, input the contact's index:\n";
        std::cout << "--> To return to menu type -1:\n" << std::endl;

        std::string input;
        std::getline(std::cin, input);

        int index = std::atoi(input.c_str());

        if (index == -1)
            return;
        if (index < 0 || index > count)
        {
            std::cout << RED << "Invalid index." << RESET << std::endl;
            continue;
        }
        displayContact(index);
    }
}

void PhoneBook::displayContactsTable()
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "|"
                  <<  std::string(9, ' ') << i << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickName()) << "|"
                  << std::endl;
    }
    std::cout << "---------------------------------------------\n" << std::endl;
}

void PhoneBook::searchContact()
{

    if (count == 0)
    {
        std::cout << RED << "No contacts available." << RESET << std::endl;
        return;
    }
    displayContactsTable();
    askContactIndexAndDisplay();
}
