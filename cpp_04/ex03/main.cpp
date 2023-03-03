#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	const std::string red("\033[0;31m");
	const std::string green("\033[1;32m");
	const std::string yellow("\033[1;33m");
	const std::string cyan("\033[0;36m");
	const std::string magenta("\033[0;35m");
	const std::string reset("\033[0m");
	std::cout<< green << "---------- Test Officiel ----------"<< std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
    me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout<< yellow << "---------- Test surcharge dleak  ----------"<< std::endl;
	IMateriaSource* src1 = new MateriaSource();// pb 
	src1->learnMateria(new Ice());
	ICharacter* Rambo = new Character("rambo");
	ICharacter* Terminator = new Character("terminator");
	AMateria* tmp1;
	tmp1 = src1->createMateria("ice");
	for (int i=0; i < 66; i++)
	{
//		tmp1 = src1->createMateria("ice");
		Terminator->equip(tmp1);
		Terminator->use(0, *Rambo);
	}
	delete Rambo;
	delete Terminator;
	delete src1;

	std::cout<< magenta << "---------- Test surcharge d'inventaire  ----------"<< std::endl;
   	IMateriaSource* materia_source = new MateriaSource();
	materia_source->learnMateria(new Cure());
	ICharacter* alf = new Character("Alf");
  	for (int i = 0; i < 156; i++)
   	{
    	alf->equip(materia_source->createMateria("cure"));
  	}
  	delete materia_source;
  	delete alf;
	std::cout<< magenta << "---------- copy et op= ----------"<< std::endl;
	IMateriaSource* ms = new MateriaSource();
	AMateria *cure = new Cure();
	ms->learnMateria(cure);
	AMateria* temp_materia = ms->createMateria("cure");
  	Character* bert = new Character("Bert");
 	bert->equip(temp_materia);
	Character *Dr = new Character(*bert);
	Dr->use(0, *bert);
	Dr->use(0, *bert);
	delete Dr;
	delete ms;
	delete bert;
	Character *dobb = new Character("Dobb");
	*dobb = *bert;
	dobb->use(0, *bert);
	delete ms;
	delete bert;
	delete Dr;
	delete dobb;
 std::cout<< magenta << "---------- FIN  ----------"<< std::endl;
	return 0;
}
