//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm();
		PresidentialPardonForm&	operator= (const PresidentialPardonForm&); // const for safety... not super nesessary

		std::string	getTarget(void) const;
		void execute(Bureaucrat const & executor) const;

	private:
		std::string target_;
};

#endif

