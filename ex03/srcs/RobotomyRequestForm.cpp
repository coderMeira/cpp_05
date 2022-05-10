//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : Form("Default Robot Parent", 72, 45)
{
	target_ = "Default";
	std::cout << "Robotomy Request " << *this << " has beed defaultly constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robot Parent", 72, 45)
{
	target_ = target;
	std::cout << "Robotomy Request " << *this << " has beed constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& param) : Form(param) {
	target_ = param.getTarget();
	std::cout << "Robotomy Request" << *this << " has beed constructed from a copy" << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm" << *this << " has been destroyed" << std::endl;
	// TODO (destructor)
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& param) {
	target_ = param.getTarget();
	return (*this);
}

const char* RobotomyRequestForm::FailureException::what() const throw()
{
	return ("Robotomy failure");
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (target_);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	int success = std::rand() % 2;
	std::cout << "< intensive drilling noises >\n";
	if (success == 1)
	{
		std::cout << target_ << " has been robotomized" << std::endl;
	}
	else
		throw (RobotomyRequestForm::FailureException());
}
