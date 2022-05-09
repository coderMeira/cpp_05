//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Form.hpp"

Form::Form() :name_("DefaultForm"), signed_(0), grade_to_sign_(150), grade_to_execute_(150)
{
	std::cout << "A default " << *this << " has been constructed" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name_(name), signed_(0), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute)
{
	if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
		throw (Form::GradeTooLowException());
	else if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << *this << " has been constructed" << std::endl;
}

Form::Form(Form const & ref) : name_(ref.getName()), signed_(ref.getSigned()), grade_to_sign_(ref.getGradeToSign()), grade_to_execute_(ref.getGradeToExecute())
{
	std::cout << *this << " has been constructed from a copy" << std::endl;
}

Form::~Form() {
	std::cout << "Form" << " destroyed" << std::endl;
	// TODO (destructor)
}

Form& Form::operator= (const Form& param) {
	signed_ = param.getSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const Form& param) {
	s << "Form " << param.getName() << " having a grade_to_sign "
		<< param.getGradeToSign() << " and a grade_to_execute "
		<< param.getGradeToExecute() << " with signed equal to "
		<< param.getSigned();
	return (s);
}

const char* Form::Exception::what() const throw()
{
	return ("FormException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
}

bool	Form::getSigned(void) const{
	return (signed_);
}

void	Form::setSigned(const bool new_value)
{
	std::cout << *this << " signed value was set to " << new_value << std::endl;
	signed_ = new_value;
}

int	Form::getGradeToSign(void) const{
	return (grade_to_sign_);
}

int	Form::getGradeToExecute(void) const{
	return (grade_to_execute_);
}

const std::string	Form::getName(void) const{
	return (name_);
}

void	Form::beSigned(Bureaucrat& bur){
	int	grade = bur.getGrade();

	if (grade > grade_to_sign_)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	signed_ = true;
	std::cout << *this << " was just signed by the bureaucrat "
		<< bur.getName() << " with a grade "
		<< bur.getGrade() << std::endl;
}
