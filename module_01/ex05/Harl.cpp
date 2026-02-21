#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void)
{
    std::cout << "Eu amo ter bacon extra para o meu hambúrguer 7XL-duplo-queijo-triplopicles-ketchup-especial. Eu realmente amo!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Eu não acredito que adicionar bacon extra custa mais dinheiro. Vocês\n"
                 "não colocaram bacon suficiente no meu hambúrguer! Se vocês tivessem colocado, eu\n"
                 "não estaria pedindo por mais!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Eu acho que mereço ter bacon extra de graça. Eu venho aqui há anos,\n"
                  "enquanto você começou a trabalhar aqui apenas no mês passado." << std::endl;
}

void Harl::error(void)
{
    std::cout << "Isto é inaceitável! Eu quero falar com o gerente agora." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[4])();

    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cerr << "Invalid level. Use: DEBUG, INFO, WARNING or ERROR." << std::endl;
}