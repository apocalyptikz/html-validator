#ifndef _STACK_H
#define _STACK_H

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
