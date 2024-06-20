#!/bin/sh

# class: Orthodox Canonical Form

if [ $# -eq 0 ]; then
	echo "usage: script [CLASS]"
	exit 1
fi

ARG1=$1

#config
CLASS=$(echo "$ARG1" | awk '{print toupper(substr($0,1,1)) substr($0,2)}')
CLASS_UPPER=$(echo "$CLASS" | tr '[:lower:]' '[:upper:]')
FILE_CPP=$CLASS.cpp
FILE_HPP=$CLASS.hpp
DATE=$(date +"%Y/%m/%d %H:%M:%S")

echo "
#ifndef "$CLASS_UPPER"_HPP
#define "$CLASS_UPPER"_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class $CLASS
{
	private:
	public:
		$CLASS(void);
		$CLASS(const $CLASS &copy);
		$CLASS &operator=(const $CLASS &copy);
		~$CLASS(void);
};

#endif /* "$CLASS_UPPER"_HPP */" >> $FILE_HPP

echo "
#include "'"'$FILE_HPP'"'"

"$CLASS"::"$CLASS"(void)
{
	if (DEBUG)
		std::cout << \"$CLASS constructor called\" << std::endl;
}

$CLASS::$CLASS(const $CLASS &copy)
{
	if (DEBUG)
		std::cout << \"$CLASS copy constructor called\" << std::endl;
	*this = copy;
}

$CLASS &$CLASS::operator=(const $CLASS &copy)
{
	if (DEBUG)
		std::cout << \"$CLASS copy assignment operator called\" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

"$CLASS"::~"$CLASS"(void)
{
	if (DEBUG)
		std::cout << \"$CLASS destructor called\" << std::endl;
}" >> $FILE_CPP

# echo "
# #include \"$FILE_HPP\"
# #include \"doctest.h\"

# TEST_SUITE(\"Class $CLASS\")
# {
# 	TEST_CASE(\"Orthodox Canonical Form\")
# 	{
# 	}
# }" >> $FILE_TEST