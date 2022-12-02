#ifndef _MUTANTSTACK_H_
#define _MUTANTSTACK_H_

#include <stack>
#include <deque>


template<class T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(MutantStack const &mutantStack) { *this = mutantStack; }
	MutantStack& operator=(MutantStack const &mutantStack) {
		return *this;
	}
	virtual ~MutantStack() {}
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(){ return this->c.begin();}
	iterator end() { return this->c.end();}
};


#endif
