
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 25, 5)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)  : target(target) {}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return this->target;
}

void ShrubberyCreationForm::executeSpecificBehavior() const
{
	std::ofstream	outFile;
	std::string		fileName = getTarget() + "_shrubbery" ;

	outFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);
	outFile << "                                   &%                       \n";
	outFile << "                            &&(  */  (&&  ,                 \n";
	outFile << "                  ,&%   ,&&   & , &&. .  %& &&   @&&        \n";
	outFile << "               .   @ .&&# & .&@ ( &  &&,&   %&@  .(#/       \n";
	outFile << "          &%    (&&,%&   %&%&   (*%#  *,&(    %/&%,(   #,   \n";
	outFile << "           && &&&% / &&& */   &/#&&,  / ..&# &    &&# .&&   \n";
	outFile << "       .&&&   .  #%@  .#  &&&%*& # @%,/& ./&.%&&.  &     &&*\n";
	outFile << "     &&#/&&# @&&   *,&%,&& &&& @ %& %  * &(&(**&&& ,&& .&%  \n";
	outFile << "    ..       *&/ #& &.%&& ,   &@#&*@%&&, .* @, &&  ,(&# (&&&\n";
	outFile << "/&&&&#.&&&   &(  &&&,&/ %&%#  &% .&    %&*@.& * , ,  @      \n";
	outFile << "     ,&%       *&# %, &&. .&& &&.&,&&&,&  %&&  #& &%% *&%   \n";
	outFile << "         %# %&&&&(&&&&&%&&&*( &&&/@&  %&@ &&(&# ,&& /&, &&. \n";
	outFile << "     *#(, &  .%&&&&&&&&&&&&&&&&&&. &.  # &&%&&&&%/%%.*/.&&/ \n";
	outFile << "      .   %, &&&.&&,,&&&    (&&&&%@&  %&&&&&&&&&&&%/ (&&&&&@\n";
	outFile << "    ,*.  &( &&, &&& &%         &&&& &&&&/            /*     \n";
	outFile << "     %&% &&                     &&&&&&/                     \n";
	outFile << "     #.                         (&&&&%                      \n";
	outFile << "                                .&&&&(                      \n";
	outFile << "                                 &&&&(                      \n";
	outFile << "                                .&&&&#                      \n";
	outFile << "                                /&&&&%                      \n";
	outFile << "                                &&&&&&                      \n";
	outFile << "                        ,/##%%%&&&&&&&&&&(                  \n";
	outFile << "                   ,&&%,.&&%..&&  #&(    #&&&%&&&&//&&#     \n";
	outFile << "               /&@&& /  &&   *&&   &%&&.&  .&&      #  & &. \n";
	outFile << "           .,/%&&%     %&  #  .&    .* @@ ,  &/       , *   \n";
	outFile << "      (    %      ,   %&     &#@     * (&   #.&#           .\n";
	outFile << "          *        &, #    /&  #      * @   *   **(@        \n";
	outFile << "                  &   *    #(        .  @*    /    #  .     \n";
	outFile << "                           # (          #             .     \n";
	outFile.close();
}

AForm	*createShrubberyCreationForm(const std::string &target)
{
	ShrubberyCreationForm	staticForm;
	ShrubberyCreationForm	*form;

	staticForm = ShrubberyCreationForm(target);
	form = new ShrubberyCreationForm(staticForm);
	return form;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->target = copy.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
