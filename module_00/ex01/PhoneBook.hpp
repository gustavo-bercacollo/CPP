#include "Contact.hpp"
#include "iostream"

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
};
