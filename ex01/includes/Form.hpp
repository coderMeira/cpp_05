//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(const Form&);
		~Form();
		Form&	operator= (const Form&); // const for safety... not super nesessary

		int					getGrade(void) const;
		const std::string	getName(void) const;
		void				beSigned(Bureaucrat&);

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

	private:
		std::string	const	name_;
		bool				signed_;
		int	const			grade_to_sign_;
		int	const			grade_to_execute_;

};

std::ostream&	operator<<(std::ostream&, const Form&);

#endif

