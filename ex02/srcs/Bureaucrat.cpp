//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("StandardBureaucrat"), grade_(150) {
	std::cout << "A default Bureaucrat has beed constructed\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		grade_ = grade;
		std::cout << "A Bureaucrat " << name_ << " with a grade of " << grade_ << " has beed constructed\n";
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& param) : name_(param.getName() + "_copy"){
	grade_ = param.getGrade();
	std::cout << "A Bureaucrat " << name_ << " with a grade " << grade_ << " has beed constructed from a copy\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "A Bureaucrat " << name_ << " with a grade " << grade_ << " has beed destroyed\n";
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& param) {
	grade_ = param.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const Bureaucrat& param) {
	s << "Bureaucrat " << param.getName() << " has a grade " << param.getGrade();
	return (s);
}

int	Bureaucrat::getGrade(void) const{
	return (grade_);
}

const std::string	Bureaucrat::getName(void) const{
	return (name_);
}

void	Bureaucrat::setGrade(const int newGrade){
	grade_ = newGrade;
}

void	Bureaucrat::decrementGrade(void){
	std::cout << "Decrementing bureaucrat " << name_ << "'s grade " << grade_ << " by 1\n";
	if (grade_ + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		grade_++;
}

void	Bureaucrat::incrementGrade(void){
	std::cout << "Incrementing bureaucrat " << name_ << "'s grade " << grade_ << " by 1\n";
	if (grade_ - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		grade_--;
}

void	Bureaucrat::signForm(Form& formRef){
	try{
		formRef.beSigned(*this);
		std::cout << "Bureaucrat " << name_ << " with a grade " << grade_
				<< " succesfully signs " << formRef << std::endl;
	}
	catch (Form::Exception &e){
		std::cout << "Bureaucrat " << name_ << " with a grade "
				<< grade_ << " cannot sign " << formRef << " because "
				<< e.what() << std::endl;
	}
}

const char* Bureaucrat::Exception::what() const throw()
{
	return ("BureaucratException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1!");
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << name_ << " sucesfully executed " << form << std::endl;
	}
	catch (Form::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
