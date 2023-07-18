#include "BitcoinExchange.hpp"
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (-1);
	}
	else
	{
		BitcoinExchange btc(argv[1]);
		return (0);
	}
}
