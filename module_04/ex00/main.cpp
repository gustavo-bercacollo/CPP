#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Animals ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Wrong Animals ===" << std::endl;
    const WrongAnimal* w_meta = new WrongAnimal();
    const WrongAnimal* w_cat = new WrongCat();

    std::cout << w_cat->getType() << std::endl;

    w_meta->makeSound(); // WrongAnimal sound
    w_cat->makeSound();  // Still WrongAnimal sound because makeSound() is NOT virtual

    delete w_meta;
    delete w_cat;

    return 0;
}
