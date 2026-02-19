#include "Zombie.hpp"

int main(int argc, char **argv)
{
    (void)argv;

    if (argc != 1) return 1;
    
    int N = 5;
    Zombie* bobs = zombieHorde(N, "BOB");
    for (int i = 0; i < N; i++)
        bobs[i].announce();

    delete[] bobs;
    return (0);
}
