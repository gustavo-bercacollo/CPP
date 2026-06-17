#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);

    try
    {
        PmergeMe p(argv + 1, argv + argc);
        p.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}