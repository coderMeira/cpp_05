//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "ex02.hpp"

int main (void)
{
	// std::srand(std::time(0)); // common practice to seed the pseudo-random number generator

	// Constructors
	std::cout << std::endl;
	std::cout << RED << "\t\t\n[ CONSTRUCTING ]\n\n" << ENDC;

	Bureaucrat				bob("Bob", 1);
	Bureaucrat				bill("Bill", 142);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robo("robo");
	PresidentialPardonForm	president("president");

	// Executing
	// ShrubberyCreationForm : sign 145, exec 137
	// RobotomyRequestForm sign 72, exec 45
	// PresidentialPardonForm sign 25, exec 5

	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;
	std::cout << YELLOW << "\t\t\n[ SHRUBBERY CREATION FORM ]\n\n" << ENDC;

	std::cout << RED << "\t\t\n[ UNSIGNED ]\n\n" << ENDC;
	bob.executeForm(shrub);
	shrub.beSigned(bob);

	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	std::cout << RED << "\t\t\n[ SIGNED ]\n\n" << ENDC;
	bob.executeForm(shrub);
	std::cout << std::endl;

	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	std::cout << RED << "\t\t\n[ GRADE TO EXE TOO LOW ]\n\n" << ENDC;
	bill.executeForm(shrub);

	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	std::cout << std::endl;
	std::cout << YELLOW << "\t\t\n[ ROBOTOMY REQUEST FORM ]\n\n" << ENDC;
	std::cout << RED << "\t\t\n[ UNSIGNED ]\n\n" << ENDC;

	bob.executeForm(robo);
	robo.beSigned(bob);

	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	std::cout << RED << "\t\t\n[ SIGNED (50% failure chance)]\n\n" << ENDC;
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	std::cout << std::endl;

	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	std::cout << RED << "\t\t\n[ GRADE TO EXE TOO LOW ]\n\n" << ENDC;
	bill.executeForm(robo);

	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	std::cout << YELLOW << "\t\t\n[ PRESIDENTIAL PARDON FORM ]\n\n" << ENDC;

	std::cout << RED << "\t\t\n[ UNSIGNED ]\n\n" << ENDC;

	bob.executeForm(president);
	president.beSigned(bob);

	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	std::cout << RED << "\t\t\n[ SIGNED ]\n\n" << ENDC;
	bob.executeForm(president);
	std::cout << std::endl;


	std::cout << RED << "\t\t\n[ GRADE TO EXE TOO LOW ]\n\n" << ENDC;
	bill.executeForm(president);

	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	std::cout << std::endl;
	std::cout << RED << "\t\t\n[ DESTRUCTORS ]\n\n" << ENDC;
	return (0);
}
