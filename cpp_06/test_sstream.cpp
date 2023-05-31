#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cctype>
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

bool is_char(const std::string& s)
{
	std::stringstream	buffer;
	int					li;
	std::string			tmp;

	bool test = (s.length() == 1);
	
	tmp = s.substr(0, s.length());
	if (!(buffer << tmp)//avant s
	|| !(buffer >> li)
	|| !(buffer >> std::ws).eof())
	{
		throw std::invalid_argument("pb charcater\n");
		return (false);
	}
	else
	{
		std::cout << red << static_cast<int>(li)<< reset <<std::endl;
		if (isprint(li))
			std::cout << magenta << static_cast<char>(li)<< reset <<std::endl;
		else
			std::cout << red << "not printable\n" << reset << std::endl;
		std::cout << green << static_cast<float>(li)<< "f" << reset <<std::endl;
		std::cout << cyan << static_cast<double>(li)<< reset <<std::endl;
		return (true);
	}


}

bool is_number(const std::string& s)
{
    std::stringstream	buffer;
	float 				ld;
	int					to_int;
	std::string			tmp;
	//std::istringstream(s) >> ld;
	
	// dans le cas ou float, je peux détecter le f, mais faudra le "flagger !"
	// pour différencier par rapport au double.. Et ne détecte pas si le f est
	// accolé ou pas
	bool test = (s.find_first_of("f",0) == s.find_last_of("f",s.length() -1)
		   	&& (s.find_first_of("f", 0) != std::string::npos));
	if (test && s.length() != 1)// ici je veux que f puisse etre affiche
	{
		tmp = s.substr(0, s.length() - 1 );
	//	printf("%s   <-s----- f détecté: tmp = %s \n",s.c_str(), tmp.c_str());
	}
	else
	{
		tmp = s.substr(0, s.length());
	}

	if (!(buffer << tmp)//avant s
	|| !(buffer >> ld)
	|| !(buffer >> std::ws).eof())
	{
		throw std::invalid_argument("impossible\n");
		std::cout << "KO \n";
		return (false);
	}
	else
	{
		std::cout << "OK\n";
		long int	li = std::strtol(s.c_str(),NULL,10);
		to_int = static_cast<int>(ld);
//		if (to_int == INT_MAX || to_int == INT_MIN)
//			std::cout << red << "erreur overflow\n" << reset << std::endl;
//		else
			std::cout << red << static_cast<int>(ld)<< reset <<std::endl;
		if (isprint(ld))
			std::cout << magenta << static_cast<char>(ld)<< reset <<std::endl;
		else
			std::cout << red << "not printable\n" << reset << std::endl;
		std::cout << green/* << std::setprecision(10)*/<< static_cast<float>(ld) << "f" << reset <<std::endl;
		std::cout << cyan << static_cast<double>(ld)<< reset <<std::endl;
		return (true);
	}
}
/*
bool is_double(double val)
{// https://stackoverflow.com/questions/3273993/how-do-i-validate-user-input-as-a-double-in-cbool answer;
 // ne fonctionne pas sur tout nb avec .0
double chk;
int double_equl = 0;     
double strdouble = 0.0;
strdouble = val;           
double_equl = (int)val;
chk = double_equl / strdouble;
if (chk == 1.00)
{
 answer = false; // val is integer
 return answer;
} else {
answer = true;  // val is double
return answer;
}
}
*/
int main()
{
	/*catch(std::bad_cast &e) 
	{ 
 		 std::cout << e.what(); // bad dynamic_cast
	}
	*/
/*	
	std::cout << std::boolalpha << is_number("   42" ) << '\n';
    std::cout << std::boolalpha << is_number("   42.0001" ) << '\n';
    std::cout << std::boolalpha << is_number("   +42.0001" ) << '\n';
    std::cout << std::boolalpha << is_number("   -42.0001" ) << '\n';
	std::cout << std::boolalpha << is_number("   -4.000e-22f" ) << '\n';
    std::cout << std::boolalpha << is_number("   10000.") << '\n';
*/
/*	try
	{// a ameliorer
		std::cout << std::boolalpha << is_number("   a3.14f") << '\n';
	}	catch (const std::invalid_argument& e)
	{
		std::cout<<"impossible"<< '\n';
	};
*/
   // 	std::cout << std::boolalpha << is_number("f") << '\n';
    try
	{	
	//	std::cout << std::boolalpha << is_number(" nan  ") << '\n';
    	std::cout << std::boolalpha << is_number("4453") << '\n';
   	//	std::cout << std::boolalpha << is_number(" nan  ") << '\n';
    //	std::cout << std::boolalpha << is_number("+inf  ") << '\n' << '\n';
//		std::cout << std::boolalpha << is_char("f") << '\n'
		std::cout << std::boolalpha << is_number("4546545211215151") << '\n';
	}
	catch(std::bad_cast &e) 
	{ 
 		 std::cout << e.what(); // bad dynamic_cast
	}
	catch(const std::invalid_argument& e) 
	{ 
 		 std::cout << e.what(); // invalid argument
	}	

	catch(const std::overflow& e) 
	{ 
 		 std::cout << e.what(); // invalid argument
	}	
	return (0);
}
