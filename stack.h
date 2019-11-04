/*
	Programmer Name : Jonathan Christian
	Date Submitted : 11/4/2019
	File Purpose : stack class header
	Date Updated :
	Purpose for Update :
	Global Variable List : n/a

		Description :
	Stores data in a std::list. Getters and setters make class
	behave like a stack

	void pop()
	pre : object is a stack
	post : removes last element in stack

	const T& top() const
	pre : object is a stack
	post : returns a reference to the last element,
	an empty stack results in undefined behavior!

	T& top()
	pre : object is a stack
	post : returns a const reference to the last element,
	an empty stack results in undefined behavior!

	void push(const T& item)
	pre : object is a stack
	post : puts item at the top (end) of the stack

	bool empty() const
	pre : object is stack
	post : returns true if the stack is empty, otherwise false

	void clear()
	pre : object is a stack
	post : removes(and destroys) all elements in stack

	Value Semantics :
	It is safe to use the copy constructorand assignent operator

	Dynamic Memory Usage :
	None

	Static Variables :
	None

	Invariant Declaration :
	None
*/

#ifndef _STACK_H
#define _STACK_H

#include <list> //for data

namespace DS {
	template<typename T>
	class stack
	{
	public:
		stack() {}
		void pop();
		const T& top() const;
		T& top();
		void push(const T&);
		bool empty() const;
		void clear();
	private:
		std::list<T> data;
	};


	template<typename T>
	void stack<T>::pop()
	{
		data.pop_back();
	}

	template<typename T>
	T& stack<T>::top()
	{
		return data.back();
	}

	template<typename T>
	const T& stack<T>::top() const
	{
		return data.back();

	}

	template<typename T>
	void stack<T>::push(const T& in)
	{
		data.push_back(in);
	}

	template<typename T>
	bool stack<T>::empty() const
	{
		return data.empty();
	}

	template<typename T>
	void stack<T>::clear()
	{
		data.clear();
	}
}
#endif // !_STACK_H
