#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;

    IMateriaSource* src = new MateriaSource();
    std::cout << "Created MateriaSource" << std::endl;

    std::cout << "Learning Ice and Cure..." << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    std::cout << "Character 'me' created" << std::endl;

    AMateria* tmp;

    std::cout << "Creating Ice materia..." << std::endl;
    tmp = src->createMateria("ice");
    std::cout << "Equipping Ice in 'me'" << std::endl;
    me->equip(tmp);

    std::cout << "Creating Cure materia..." << std::endl;
    tmp = src->createMateria("cure");
    std::cout << "Equipping Cure in 'me'" << std::endl;
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    std::cout << "Character 'bob' created" << std::endl;

    std::cout << "Using slot 0 on bob:" << std::endl;
    me->use(0, *bob);

    std::cout << "Using slot 1 on bob:" << std::endl;
    me->use(1, *bob);

    std::cout << "\n===== CLEANUP =====" << std::endl;

    std::cout << "Deleting bob" << std::endl;
    delete bob;

    std::cout << "Deleting me" << std::endl;
    delete me;

    std::cout << "Deleting source" << std::endl;
    delete src;

    return 0;
}
