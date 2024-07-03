#include "MutantStack.hpp"
#include <vector>
#include <list>

// #define FAIL
// #define DEFAULT
// #define VECTOR
#define LISTggi

void	listTest()
{
	MutantStack< int, std::list<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack< int, std::list<int> >::iterator it = mstack.begin();
	MutantStack< int, std::list<int> >::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack< int, std::list<int> > s(mstack);
#ifdef FAIL
	it = s.begin();
	while (it != s.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
#endif
}

void	vectorTest()
{
	MutantStack< int, std::vector<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack< int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack< int, std::vector<int> >::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack< int, std::vector<int> > s(mstack);
#ifdef FAIL
	it = s.begin();
	while (it != s.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
#endif
}

void	dequeTest()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
#ifdef FAIL
	it = s.begin();
	while (it != s.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
#endif
}

int main()
{
#ifdef DEFAULT
	std::cout << "===== deque Test =====" << std::endl;
	dequeTest();
#endif
#ifdef VECTOR
	std::cout << "===== vector Test =====" << std::endl;
	vectorTest();
#endif
#ifdef LIST
	std::cout << "===== list Test =====" << std::endl;
	listTest();
#endif
	return 0;
}