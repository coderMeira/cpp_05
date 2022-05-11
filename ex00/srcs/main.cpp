//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Bureaucrat.hpp"
#include "ex00.hpp"

int main(void)
{
	// Constructor with a bad grade
	// -49
	std::cout << RED << "\t\t\n[ CONSTRUCTING WITH GRADE -49 ]\n\n" << ENDC;
	try
	{
		Bureaucrat bill("Bill", -49);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}

	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	// 256
	std::cout << RED << "\t\t\n[ CONSTRUCTING WITH GRADE 256 ]\n\n" << ENDC;
	try
	{
		Bureaucrat bill("Bill", 256);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	// Normal increment/decrement and "<<" overload
	std::cout << RED << "\t\t\n[ IN/DECREMENT + \"<<\" overload: ]\n\n" << ENDC;
	Bureaucrat bob("Bob", 1);
	std::cout << bob << std::endl;
	try
	{
		bob.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	// "<<" operator overload used
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	// "<<" operator overload used
	std::cout << bob;
	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	// Increment 1 exception
	std::cout << RED << "\t\t\n[ INCREMENT GRADE 1 ]\n\n" << ENDC;
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	// Decrement 150 exception
	std::cout << RED << "\t\t\n[ DECREMENT GRADE 150 ]\n\n" << ENDC;
	bob.setGrade(150);
	std::cout << bob << std::endl;
	try
	{
		bob.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;

	std::cout << RED <<"\t\t\n[ DESTRUCTORS ]\n\n" << ENDC;
	return (0);
}
