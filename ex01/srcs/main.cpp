//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Bureaucrat.hpp"
#include "ex01.hpp"

int	main(void)
{
	// Constructors
	std::cout << std::endl;
	std::cout << RED << "\t\t\n[ CONSTRUCTING ]\n\n" << ENDC;

	Bureaucrat	bob("Bob", 1);
	Bureaucrat	bill("Bill", 132);

	Bureaucrat & bob_ref = bob;
	Bureaucrat & bill_ref = bill;

	Form		a("A13", 4, 6);
	Form		b("B97", 146, 135);

	std::cout << YELLOW << "\n\n****************************************************\n" << ENDC;
	std::cout << RED << "\t\t\n[ CREATE A FORM WITH GRADES TOO LOW ]\n\n" << ENDC;
	try
	{
		Form	c("C46", 489, 1435);
	}
	catch (Form::Exception &e)
	{
		std::cout << "Constructor failure: " << e.what() << std::endl; //the grade is too low
	}
	std::cout << RED << "\t\t\n[ CREATE A FORM WITH GRADES TOO high ]\n\n" << ENDC;
	try
	{
		Form	c("D143", -583, -800);
	}
	catch (Form::Exception &e)
	{
		std::cout << "Constructor failure: " << e.what() << std::endl; //the grade is too high
	}

	// Sign forms
	std::cout << YELLOW << "\t\t\n[ SIGN FORMS ]\n\n" << ENDC;

	// Sign OK
	std::cout << RED << "\t\t\n[ SIGN OK ]\n\n" << ENDC;
	bob_ref.signForm(a);
	std::cout << a << " just showed its current status" << std::endl;
	a.setSigned(false);
	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	// Sign KO
	std::cout << RED << "\t\t\n[ SIGN KO ]\n\n" << ENDC;
	bill_ref.signForm(a);
	std::cout << a << " just showed its current status" << std::endl;
	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	// Sign OK
	std::cout << RED << "\t\t\n[ SIGN OK ]\n\n" << ENDC;
	bob.signForm(b);
	std::cout << b << " just showed its current status" << std::endl;
	b.setSigned(false);
	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	// Sign OK
	std::cout << RED << "\t\t\n[ SIGN OK ]\n\n" << ENDC;
	bill.signForm(b);
	std::cout << b << " just showed its current status" << std::endl;
	std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << ENDC;

	std::cout << std::endl;
	std::cout << RED << "\t\t\n[ DESTRUCTORS ]\n\n" << ENDC;
	return (0);
	//-------------------------------------------------------
}
