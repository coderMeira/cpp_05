//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <iostream>
#include "ex02.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();
		Bureaucrat&	operator= (const Bureaucrat&); // const for safety... not super nesessary

		int					getGrade(void) const;
		const std::string	getName(void) const;
		void				setGrade(const int);
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form&);
		void				executeForm(Form const &);

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const	std::string	name_;
		int					grade_;
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif

