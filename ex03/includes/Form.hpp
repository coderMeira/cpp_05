//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form&);
		virtual ~Form();
		Form&	operator= (const Form&); // const for safety... not super nesessary

		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getSigned(void) const;
		void				setSigned(const bool);
		const std::string	getName(void) const;
		void				beSigned(Bureaucrat& b);
		virtual void		execute(Bureaucrat const &b) const = 0;

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		class UnsignedFormException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string	const	name_;
		bool				signed_;
		int	const			grade_to_sign_;
		int	const			grade_to_execute_;

};

std::ostream&	operator<<(std::ostream&, const Form&);
#include "Bureaucrat.hpp"

#endif

