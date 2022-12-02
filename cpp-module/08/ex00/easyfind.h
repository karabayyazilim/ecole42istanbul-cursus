#ifndef _EASYFIND_H_
#define _EASYFIND_H_

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return it;
}

#endif
