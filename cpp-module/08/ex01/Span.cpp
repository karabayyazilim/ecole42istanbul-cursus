#include "Span.h"

Span::Span() {
	size = 0;
}

Span::Span(unsigned int n) {
	size = n;
	v.reserve(n);
}

Span::Span(Span const & span) {
	*this = span;
}

Span &Span::operator=(const Span &span) {
	if (this == &span)
		return *this;
	size = span.size;
	this->v = span.v;
	return *this;
}

void Span::addNumber(int number) {
	if(v.size() == size)
		throw VectorIsFullException();
	v.push_back(number);
}

int Span::shortestSpan() {
	if(v.size() < 2)
		throw VectorIsTooSmallException();
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	int min = *tmp.begin();
	for(std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
		if(*std::next(it) - *it < min)
			min = *std::next(it) - *it;
	return(min);
}

int Span::longestSpan() {
	if(v.size() < 2)
		throw VectorIsTooSmallException();
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	return(*(tmp.end() - 1) - *tmp.begin());
}

const char *Span::VectorIsFullException::what() const throw() {
	return "Vector is full";
}

const char *Span::VectorIsTooSmallException::what() const throw() {
	return "Vector is too small";
}

Span::~Span() {
}


