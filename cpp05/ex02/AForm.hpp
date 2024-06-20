
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


#ifndef DEBUG
#define DEBUG 0
#endif

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeRequireSign;
		const int			gradeRequireExec;
		void				setIsSigned(bool isSigned);
	public:
		AForm(void);
		AForm(const std::string name, \
			const int gradeRequireSign, const int gradeRequireExec);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm(void);

		const std::string	getName(void) const;
		int					getRequireGradeSing(void) const;
		int					getRequireGradeExec(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
		void				signForm(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;
};

class CannotExecuteException : public std::exception {
	private:
		const std::string msg;
	public:
		CannotExecuteException(void);
		virtual ~CannotExecuteException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
		virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
};

std::ostream	&operator<<(std::ostream& out, AForm &AForm);

#endif /* FORM_HPP */
