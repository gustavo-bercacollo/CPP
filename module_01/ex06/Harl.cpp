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
    Level levelIndex = UNKNOWN;

    if (level == "DEBUG")
        levelIndex = DEBUG;
    else if (level == "INFO")
        levelIndex = INFO;
    else if (level == "WARNING")
        levelIndex = WARNING;
    else if (level == "ERROR")
        levelIndex = ERROR;

    switch (levelIndex)
    {
        case DEBUG:
            debug();
        case INFO:
            info();
        case WARNING:
            warning();
        case ERROR:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}
