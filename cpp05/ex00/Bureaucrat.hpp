
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat(void);

		void		setGrade(const int &grade);
		std::string	getName() const;
		int			getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, Bureaucrat &bureaucrat);

#endif /* BUREAUCRAT_HPP */
