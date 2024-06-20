
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include <exception>

#ifndef DEBUG
#define DEBUG 0
#endif

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat(void);

		std::string	getName(void) const;
		void		setGrade(int grade);
		int			getGrade(void) const;
		void		incrementGrade();
		void		decrementGrade();
		void		executeForm(AForm const &form);
};

class GradeTooHighException : public std::exception {
	private:
		const std::string msg;
	public:
		GradeTooHighException(const char *msg);
		virtual ~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
		virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
};

class GradeTooLowException : public std::exception {
	private:
		const std::string msg;
	public:
		GradeTooLowException(const char *msg);
		virtual ~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
		virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
};

std::ostream	&operator<<(std::ostream& out, Bureaucrat &bureaucrat);

#endif /* BUREAUCRAT_HPP */
