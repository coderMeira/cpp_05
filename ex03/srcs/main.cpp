//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "ex03.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	// Constructors
	std::cout << std::endl;
	std::cout << RED << "CONSTRUCTING:" << ENDC << std::endl;
	std::cout << RED << "----------------------------" << ENDC << std::endl;

	Intern	intern;
	Form	*shrub_form;
	Form	*robo_form;
	Form	*president_form;
	Form	*unknown_form;
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << RED << "INTERN TESTS:" << ENDC << std::endl;
	std::cout << RED << "----------------------------" << ENDC << std::endl;

	// Shrub:
	std::cout << YELLOW << "\nTesting makeForm(\"shrubbery creation\", \"shrub\")\n" << ENDC;
	shrub_form = intern.makeForm("shrubbery creation", "shrub");
	std::cout << *shrub_form << " was just created " << std::endl << std::endl;

	// Robo:
	std::cout << YELLOW << "\nTesting makeForm(\"robotomy request\", \"robo\")\n" << ENDC;
	robo_form = intern.makeForm("robotomy request", "robo");
	std::cout << *robo_form << " was just created " << std::endl << std::endl;

	// President:
	std::cout << YELLOW << "\nTesting makeForm(\"presidential pardon\", \"president\")\n" << ENDC;
	president_form = intern.makeForm("presidential pardon", "president");
	std::cout << *president_form << " was just created " << std::endl << std::endl;


	// Unknown:
	std::cout << YELLOW << "\nTesting makeForm(\"driving licence\", \"drive\")\n" << ENDC;
	try
	{
		unknown_form = intern.makeForm("driving licence", "drive");
		std::cout << *unknown_form << " was just created " << std::endl << std::endl;
	}
	catch (Intern::Exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << RED << "DESTRUCTORS:" << ENDC << std::endl;
	std::cout << RED << "----------------------------" << ENDC << std::endl;
	delete shrub_form;
	delete robo_form;
	delete president_form;
	if (unknown_form != NULL)
		delete unknown_form;
	return (0);
	//-------------------------------------------------------
}
