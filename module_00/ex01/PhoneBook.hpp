#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Includes.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
        int i;

    public:
        PhoneBook();
        void addContact();
        void searchContact();
        void displayContactsTable();
        void displayContact(int index);
        void askContactIndexAndDisplay();
};

#endif