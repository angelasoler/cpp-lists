
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeRequireSign;
		const int			gradeRequireExec;
		void				setIsSigned(bool isSigned);
	public:
		Form(void);
		Form(const std::string name, \
			const int gradeRequireSign, const int gradeRequireExec);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form(void);

		const std::string	getName(void);
		int					getRequireGradeSing(void);
		int					getRequireGradeExec(void);
		bool				getIsSigned(void);
		void				beSigned(Bureaucrat &bureaucrat);
		void				signForm(Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream& out, Form &Form);

#endif /* FORM_HPP */
