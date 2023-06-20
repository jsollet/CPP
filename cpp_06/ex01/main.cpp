#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *d1 = new Data();
	Data *d = new Data();
	uintptr_t	ui;

	d->aInt = 42;
	d->aFloat = 0.123;
	d->aString = "salut...";

	
	std::cout << yellow <<  "ui = Serializer::serialize(d);\nd = Serializer::deserialize(ui);\n\n"<< reset;
	std::cout << red << "adresse de uintptr_t et de la structure" << cyan << " Data (AVANT)\n" << red;
	std::cout << &ui << "\n" << cyan << &d << "\n";
	std::cout << green <<"Contenu de Data d avant serialise\n";
	std::cout << "d.aInt = " << d->aInt << std::endl;
	std::cout << "d.aFloat = " << d->aFloat << std::endl;
	std::cout << "d.aString = " << d->aString << std::endl << reset;
	
	ui = Serializer::serialize(d);
	d = Serializer::deserialize(ui);
	
	std::cout << red <<"adresse de uintptr_t et de la structure" << cyan <<"  Data (APRES)\n" << red;
	std::cout << &ui << "\n" << cyan << &d << "\n";
	std::cout << green <<"Contenu de Data d apres deserialise\n";
	std::cout << "d.aInt = " << d->aInt << std::endl;
	std::cout << "d.aFloat = " << d->aFloat << std::endl;
	std::cout << "d.aString = " << d->aString << std::endl << reset;

	delete (d1);
	d1 = Serializer::deserialize(ui);
	std::cout << red <<"adresse de la structure Data d1 (APRES)\n";
	std::cout << &d1 << "\n";
	std::cout << green <<"Contenu de Data d1 apres deserialise\n";
	std::cout << "d1.aInt = " << d1->aInt << std::endl;
	std::cout << "d1.aFloat = " << d1->aFloat << std::endl;
	std::cout << "d1.aString = " << d1->aString << reset << std::endl;

	delete (d);
}
