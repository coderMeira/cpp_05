//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator= (const ShrubberyCreationForm&); // const for safety... not super nesessary

		std::string	getTarget(void) const;
		void execute(Bureaucrat const & executor) const;

	private:
		std::string	target_;
};

#endif

