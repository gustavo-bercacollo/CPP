#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "----- BASIC TEST -----" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n----- ARRAY TEST -----" << std::endl;

    Animal* animals[10];

    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();

    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 10; i++)
        delete animals[i];

    std::cout << "\n----- DEEP COPY TEST -----" << std::endl;

    Dog dog1;
    Dog dog2;

    dog1 = dog2;

    return 0;
}
