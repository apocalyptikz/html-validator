/*
	Programmer Name : Jonathan Christian
	Date Submitted : 11/4/2019
	File Purpose : queue class header
	Date Updated :
	Purpose for Update :
	Global Variable List : n/a
 
	Description:
		Stores data in a std::list. Getters and setters make class 
		behave like a queue

	void dequeue()
		pre: object is a queue
		post: removes first element in queue

	const T& front() const
		pre: object is a queue
		post: returns a reference to the first element, 
			an empty queue results in undefined behavior!

	T& front()
		pre: object is a queue 
		post: returns a const reference to the first element,
			an empty queue results in undefined behavior!

	void enqueue (const T& item)
		pre: object is a queue
		post: puts item at the end of the queue

	bool empty() const
		pre: object is queue
		post: returns true if the queue is empty, otherwise false

	void clear()
		pre: object is a queue
		post: removes (and destroys) all elements in queue

	Value Semantics:
		It is safe to use the copy constructor and assignent operator

	Dynamic Memory Usage:
		None

	Static Variables:
		None
			
	Invariant Declaration:
		None

 */

#ifndef _QUEUE_H
#define _QUEUE_H

#include <list> //for data

namespace DS {
	template<typename T>
	class queue
	{
	public:
		typedef size_t size_type;
		queue() {}
		void dequeue();
		const T& front() const;
		T& front();
		void enqueue(const T&);
		bool empty() const;
		void clear();
	private:
		std::list<T> data;
	};

	template<typename T>
	void queue<T>::dequeue()
	{
		data.pop_front();
	}

	template<typename T>
	const T& queue<T>::front() const
	{
		return data.front();
	}

	template<typename T>
	T& queue<T>::front()
	{
		return data.front();
	}

	template<typename T>
	void queue<T>::enqueue(const T& qIn)
	{
		data.push_back(qIn);
	}

	template<typename T>
	bool queue<T>::empty() const
	{
		return data.empty();
	}

	template<typename T>
	void queue<T>::clear()
	{
		data.clear();
	}
}

#endif // !_QUEUE_H