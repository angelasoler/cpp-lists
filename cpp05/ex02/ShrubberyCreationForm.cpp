
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

	std::cout << "Target:" << getTarget() << std::endl;

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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
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
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
