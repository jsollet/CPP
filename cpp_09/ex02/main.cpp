#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << red << "nothing to sort\n";
	else
		PmergeMe(argc, argv);
	return (0);
}
