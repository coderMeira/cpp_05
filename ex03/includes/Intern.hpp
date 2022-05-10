//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern&);
		~Intern();
		Intern&	operator= (const Intern&); // const for safety... not super nesessary

		Form	*makeForm(std::string formName, std::string formTarget);

		class Exception : public std::exception{
			public:
				virtual const char * what() const throw();
		};
};

std::ostream&	operator<<(std::ostream&, const Intern&);

#endif

