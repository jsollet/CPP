#include <iostream>
#include <sstream>
#include <cstdlib>
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

bool is_number(const std::string& s)
{
    std::stringstream	buffer;
	float 				ld;
	std::string			tmp;
	//std::istringstream(s) >> ld;
	
	// dans le cas ou float, je peux détecter le f, mais faudra le "flagger !"
	// pour différencier par rapport au double.. Et ne détecte pas si le f est
	// accolé ou pas
	bool test = (s.find_first_of("f",0) == s.find_last_of("f",s.length() -1) &&
	(s.find_first_of("f", 0) != std::string::npos));
	if (test)
	{
		tmp = s.substr(0, s.length() - 1);
		printf("%s   <-s----- f détecté: tmp = %s \n",s.c_str(), tmp.c_str());
	}
	else
	{
		tmp = s.substr(0, s.length());
	}

	if (!(buffer << tmp)//avant s
	|| !(buffer >> ld)
	|| !(buffer >> std::ws).eof())
	{
		std::cout << "KO \n";
		return (false);
	}
	else
	{
		std::cout << "OK\n";
		long int	li = std::strtol(s.c_str(),NULL,10);

		std::cout << magenta << static_cast<char>(ld)<< reset <<std::endl;
		std::cout << red << static_cast<int>(ld)<< reset <<std::endl;
		std::cout << green << static_cast<float>(ld)<< "f" << reset <<std::endl;
		std::cout << cyan << static_cast<double>(ld)<< reset <<std::endl;
		return (true);
	}
}

int main()
{
/*  std::cout << std::boolalpha << is_number("   42" ) << '\n';
    std::cout << std::boolalpha << is_number("   42.0001" ) << '\n';
    std::cout << std::boolalpha << is_number("   +42.0001" ) << '\n';
    std::cout << std::boolalpha << is_number("   -42.0001" ) << '\n';
*/	std::cout << std::boolalpha << is_number("   -4.000e-22f" ) << '\n';
    std::cout << std::boolalpha << is_number("   10000.") << '\n';
    std::cout << std::boolalpha << is_number("   3.14f ") << '\n';
    std::cout << std::boolalpha << is_number("   31445654 ") << '\n';
    std::cout << std::boolalpha << is_number(" nan  ") << '\n';
    std::cout << std::boolalpha << is_number("+inf  ") << '\n';
  //  std::cout << std::boolalpha << is_number("f") << '\n';
}
