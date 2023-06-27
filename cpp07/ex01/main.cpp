#include "iter.hpp"

int main()
{
	int			intArray[10] = {0,1,2,3,4,5,6,7,8,9};
	double		floatArray[5] = {12.01, 17.89, -0.051, 19.97, -4000.09};
	char		charArray[6] = {'j', 's', 'o', 'l','l','1'};
	std::string	stringArray[4] = {"Ce programme ","démontre ", 
	"la fonction template ", "(void) iter(T a[], size_t size, void (*fn)(T &))"};

	std::cout  << std::endl;
	iter(stringArray, size(stringArray), printInline);
	std::cout  << std::endl;
	iter(intArray, size(intArray), printSpace);
	std::cout  << std::endl;
	iter(intArray, size(intArray), square);
	iter(intArray, size(intArray), printSpace);
	std::cout  << std::endl;
	iter(floatArray, size(floatArray), printSpace);
	std::cout  << std::endl;
	iter(floatArray, size(floatArray), add1);
	iter(floatArray, size(floatArray), printSpace);
	std::cout  << std::endl;
	iter(charArray, size(charArray), printInline);
	std::cout  << std::endl;
	iter(charArray, size(charArray), add1);
	iter(charArray, size(charArray), printInline);
	std::cout  << std::endl;
	return (0);
}
