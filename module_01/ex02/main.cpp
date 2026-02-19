#include "iostream"
#include "string"

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Endereço de memória da variável string:    " << &string << std::endl;
    std::cout << "Endereço de memória mantido por stringPTR: " << stringPTR << std::endl;
    std::cout << "Endereço de memória mantido por stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;
    
    std::cout << "Valor da variável string:     " << string << std::endl;
    std::cout << "Valor apontado por stringPTR: " << *stringPTR << std::endl;
    std::cout << "Valor apontado por stringREF: " << stringREF << std::endl;

    return 0;
}