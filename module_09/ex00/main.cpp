#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	BitcoinExchange btc;

	btc.loadDatabase("data.csv");
	btc.processInput(argv[1]);
}
