#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>
#include <cstdlib>

bool	ShrubberyCreationForm::debug = false;

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:Form("Shrubbery Creation Form", false, 145, 137), target(target)
{
	if (debug)
		std::cout << "Param shrubbery  Ctor " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation Form", false, 145, 137), target("")
{
	if (debug)
		std::cout << "Default shrubbery Ctor " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
:Form("Shrubbery Creation Form", false, 145, 137), target(rhs.getTarget())
{
	if (debug)
		std::cout << "Copy.shrubbery  form Ctor " << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	rhs.getTarget();
	if (debug)
		std::cout << "Copy.shrubbery  form Ctor " << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (debug)
		std::cout << "ShrubberyCreationForm Dtor " << std::endl;
}

const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecLevel())
		throw Form::FormNotExecuted();
	else if (this->getStatus() == false)
		throw Form::FormNotSigned();
	else
	{
		std::ofstream	file;
		std::string		ext="_shrubbery";
		std::string		fileName = this->target + "_shrubbery";
		file.open(fileName.c_str(), std::ios::out); //
		file << "				cce*88oo      "  << std::endl;
		file << "           C8O8*8Q8P*Ob o8oo "  << std::endl;
		file << "         dOB*9*O8P*UOpugO9*D "  << std::endl;
		file << "        CO*9O0*89PBCOPL*SOBB*"  << std::endl;
		file << "        Cgg*bU8*UO*OOd*UOdcb "  << std::endl;
		file << "          6O*U  /p  gc*U*dpP "  << std::endl;
		file << "           ####/djjjP*       "  << std::endl;
		file << "             |||//           "  << std::endl;
		file << "             |||//           "  << std::endl;
		file << "             |||||           "  << std::endl;
		file << "       .....//||||'....      "  << std::endl;
		file.close();
	}
		return (true);
}
