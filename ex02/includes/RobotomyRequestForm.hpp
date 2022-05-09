//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

#include <iostream>
#include "ex02.hpp"

class Form;

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(const RobotomyRequestForm&);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator= (const RobotomyRequestForm&); // const for safety... not super nesessary

		std::string	getTarget(void) const;
		void execute(Bureaucrat const & executor) const;

		class FailureException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string	target_;
};

std::ostream&	operator<<(std::ostream&, const RobotomyRequestForm&);

#endif

