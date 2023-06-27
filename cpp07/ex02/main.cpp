#include "Array.hpp"

int main()
{
	Array<int> empty;
	std::cout << "\n\ttest de Array<int> empty.\n";
	std::cout << "adresse de empty = "<< &empty << std::endl;
	try
	{
		std::cout << "sa valeur (doit faire une exception)\n" << red << empty[0] << std::endl;
	}catch(const std::exception& e)
	{
		std::cout << e.what() << reset << '\n';
	}
	std::cout << std::endl << "\n\ttest int *a = new int()\n" << std::endl;

	int * a = new int();
	std::cout << "a = " << a << std::endl;
	std::cout << "*a = " << *a << std::endl;
	delete a;

	std::cout << "\n\ttest invalide index.\n";
	Array<int> test(42);
	try
	{
		std::cout << "test[-4]\n" << red << test[-4] << std::endl;
	}catch(const std::exception& e)
	{
		std::cout << e.what() << reset << '\n';
	}
	try
	{
		std::cout << "test["<< test.size() << "] (test.size() = 42)\n" << red << test[test.size()] << std::endl;
	}catch(const std::exception& e)
	{
		std::cout << e.what() << reset << '\n';
	}

	std::cout << std::endl << "\n\ttest copie Array<int>(10) viCopy(vi)\n" << std::endl;
	Array<int> vi(10);
	for (unsigned int i= 0; i < vi.size(); ++i)
		vi[i] = i * i;
	Array<int> vi_equ(20);
	for (unsigned int i= 0; i < vi_equ.size(); ++i)
		vi_equ[i] = 10 * i;
	Array<int> viCopy(vi);
	std::cout << green << "Adresse original :\t"<< &vi <<"\nAdresse copie :\t\t"<<
	&viCopy << reset;
	std::cout <<"\n(juste après la copie...)\n";
	for (unsigned int i= 0; i < vi.size(); ++i)
		std::cout << "v[" <<i<<"]  =  " << vi[i] << "\t\tviCopy["<< i<< "] = " << viCopy[i] <<  std::endl;
	std::cout <<"(juste après avoir modifier la copie...)\n";
	for (unsigned int i= 0; i < viCopy.size(); ++i)
		viCopy[i] = viCopy[i] - 2*(i*i);
	for (unsigned int i= 0; i < vi.size(); ++i)
		std::cout << "v[" <<i<<"]  =  " << vi[i] << "\t\tviCopy["<< i<< "] = " << viCopy[i] <<  std::endl;
	
	std::cout << "\n\ttest de size(vi) = " << vi.size() << std::endl;
	std::cout << "\n\ttest assignation copie vi_equ = vi\n";
	std::cout << "Avant |vi_equ| = "<< vi_equ.size() << "  |vi| =" <<
	vi.size() << std::endl;
	std::cout << green <<"Avant &vi_equ = "<< &vi_equ << "  &vi =" <<
	&vi << reset <<std::endl;
	vi_equ = vi;
	std::cout  <<"Apres |vi_equ| = "<< vi_equ.size() << "  |vi| =" <<
	vi.size() << std::endl;
	std::cout << green << "Apres &vi_equ = "<< &vi_equ << "  &vi =" <<
	&vi << reset <<std::endl;
	for (unsigned int i= 0; i < vi.size(); ++i)
		std::cout << "vi_equ[" <<i<<"]  =  " << vi_equ[i] << "    vi["<< i<< "] = " << vi[i] <<  std::endl;
	
	std::cout << red <<"\n\ttest (Array<Array<int>> (3x10)) " <<reset << std::endl;
	Array<int>	col(10);
	Array<Array<int> >	raw(3);
	for (unsigned int r = 0; r < raw.size(); ++r)
	{
		for (unsigned int c = 0; c < col.size(); ++c)
			col[c] = c * (r + 1);
		raw[r] = col;
	}
	for (unsigned int r = 0; r < raw.size(); ++r)
	{
		for (unsigned int c = 0; c < col.size(); ++c)
			std::cout << green<< raw[r][c] << "\t" ;
		std::cout << reset <<std::endl;
	}

	std::cout << red <<"\n\ttest (Array<Array<double>> (3x10)) " <<reset << std::endl;
	Array<double>	cold(10);
	Array<Array<double> >	rawd(3);
	for (unsigned int r = 0; r < rawd.size(); ++r)
	{
		for (unsigned int c = 0; c < cold.size(); ++c)
		cold[c] = 0.4324* (r+c+1);
		rawd[r] = cold;
	}
	for (unsigned int r = 0; r < rawd.size(); ++r)
	{
		for (unsigned int c = 0; c < cold.size(); ++c)
			std::cout << std::setw(12) << std::setprecision(6) << magenta<< rawd[r][c] << "\t" ;
		std::cout << reset <<std::endl;
	}

	std::cout << red <<"\n\ttest (Array<std::string> (4)) " <<reset << std::endl;
	Array<std::string>	phrase(4);
	phrase[0] = "Should I stay or should I go?\n";
	phrase[1] = "If I go, there will be trouble\n";
	phrase[2] = "And if I stay it will be double\n";
	phrase[3] = "So come on and let me know (the Clash)\n";
	for (unsigned int i = 0; i < phrase.size(); ++i)
		std::cout<<cyan << phrase[i];
	std::cout << red <<"\n--------FIN PROGRAMME--------\n"<< reset;
	return (0);

}
