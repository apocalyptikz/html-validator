#ifndef _QUEUE_H
#define _QUEUE_H

namespace DS {
	template<typename T>
	class queue
	{
		queue();
		void dequeue();
		const T& front() const;
		T& front();
		void enqueue(const T&);
		bool empty() const;
		void clear();

	};

	template<typename T>
	queue<T>::queue()
	{

	}

	template<typename T>
	void queue<T>::dequeue()
	{

	}

	template<typename T>
	const T& queue<T>::front() const
	{

	}

	template<typename T>
	T& queue<T>::front()
	{

	}

	template<typename T>
	void queue<T>::enqueue(const T&)
	{

	}

	template<typename T>
	bool queue<T>::empty() const
	{

	}

	template<typename T>
	void queue<T>::clear()
	{

	}
}

#endif // !_QUEUE_H