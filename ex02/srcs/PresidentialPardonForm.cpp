//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Default Robot Parent", 25, 5)
{
	target_ = "Default";
	std::cout << "Presidential Request " << *this << " has beed defaultly constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Robot Parent", 25, 5)
{
	target_ = target;
	std::cout << "Presidential Request " << *this << " has beed constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& param) {
	target_ = param.getTarget();
	std::cout << "Presidential Request" << *this << " has beed constructed from a copy" << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm" << *this << "has been destroyed" << std::endl;
	// TODO (destructor)
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& param) {
	target_ = param.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (target_);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
		std::cout << target_ << " was pardonned by Zaphod Beeblebrox\n";
}
