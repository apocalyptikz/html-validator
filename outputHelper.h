
#ifndef OUTPUTHELPER_H_
#define OUTPUTHELPER_H_

#include <list>
#include "stack.h"
#include "queue.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& list) {
	out << "[";
	if ( !list.empty() ) {
		auto it = list.begin();
		out << *it;
		for ( ++it; it != list.end(); ++it)
			std::cout << ", " << *it;
	}
	out << "]";
	return out;
}

//Precondition: None
//Postcondition: STACK IS EMPTIED and inserted into stream
template <typename T>
std::ostream& operator<<(std::ostream& out, DS::stack<T>& stack) {
	out << "[";
	if ( !stack.empty() ) {
		out << stack.top();
		for ( stack.pop(); !stack.empty(); stack.pop())
			std::cout << ", " << stack.top();
	}
	out << "]";
	return out;
}


#endif /* OUTPUTHELPER_H_ */
