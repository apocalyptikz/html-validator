#ifndef _QUEUE_H
#define _QUEUE_H

namespace DS {
	template<typename T>
	class queue
	{
	public:
		typedef size_t size_type;
		queue();
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
	queue<T>::queue()
	{
		
	}

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