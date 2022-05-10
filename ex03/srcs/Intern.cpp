//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "An Intern has been constructed\n";
}

Intern::Intern(const Intern& param) {
	std::cout << "An Intern has been constructed from a copy\n";
	(void)param;
}

Intern::~Intern() {
	std::cout << "Intern" << " destroyed" << std::endl;
	// TODO (destructor)
}

Intern& Intern::operator= (const Intern& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const Intern& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

const char* Intern::Exception::what() const throw()
{
	return ("Unknown Form exception");
}

static Form*	new_shrub(std::string target)
{
	Form	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

static Form*	new_robo(std::string target)
{
	Form	*robo = new RobotomyRequestForm(target);
	return (robo);
}
static Form*	new_president(std::string target)
{
	Form	*president = new PresidentialPardonForm(target);
	return (president);
}

Form	*Intern::makeForm(std::string formName, std::string formTarget)
{
	Form	*(*formPtr[3])(std::string target) = {new_shrub, new_robo, new_president};
	std::string	msg[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form	*ret = NULL;

	for (int i = 0; i < 3; i++){
		if (formName == msg[i])
		{
			ret = formPtr[i](formTarget);
			break ;
		}
	}
	if (ret)
		std::cout << "Intern creates " << *ret << std::endl;
	else
		throw (Intern::Exception());
	return (ret);
}
