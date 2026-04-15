#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("A", 50);
        Bureaucrat b2("B", 10);

        Form f("Contrato", 30, 10);

        b1.signForm(f);
        b2.signForm(f);

        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}