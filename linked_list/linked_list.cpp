#include <memory>
#include <functional>

template<typename T>
class LinkedList {


public:
	LinkedList() = default;


	void AddFront(const T& value);
	void AddBack(const T& value);
	bool Contains(const T& value) const;
	bool Search(const std::function<bool(const T&)> predicate) const;


	void RemoveFromList(const T& value)
	{
		std::shared_ptr<Node<T>> p = mHead;
		std::shared_ptr<Node<T>> e = nullptr;

		if (Search(value) != nullptr)
		{
			if (e == nullptr)
			{
				mHead = p->mNext;
			}
			else
			{
				e->mNext = p->mNext;
			}
		}
	}

private:
	template<typename T>
	struct Node
	{
		Node(const T& value) : mValue(value) {}
		Node(const T& value, const std::shared_ptr<Node> next) : mValue(value), mNext(next) {}

		T mValue;
		std::shared_ptr<Node> mNext = nullptr;
	};

private:
	std::shared_ptr<Node<T>> mHead = nullptr;
};


template<typename T>
bool LinkedList<T>::Search(const std::function<bool(const T&)> predicate) const
{
	std::shared_ptr<Node<T>> p = mHead;
	while (p != nullptr && !predicate(p->mValue))
	{
		p = p->mNext;
	}

	return p != nullptr;
}

template<typename T>
bool LinkedList<T>::Contains(const T& value) const
{
	std::shared_ptr<Node<T>> p = mHead;
	while (p != nullptr && p->mValue != value)
	{
		p = p->mNext;
	}

	return p != nullptr;

}

template<typename T>
void LinkedList<T>::AddBack(const T& value)
{
	if (!mHead)
	{
		mHead = std::make_shared<Node<T>>(value);
	}
	else
	{
		std::shared_ptr<Node<T>> p = mHead;
		while (p->mNext)
		{
			p = p->mNext;
		}
		p->mNext = std::make_shared<Node<T>>(value);
	}
}

template<typename T>
void LinkedList<T>::AddFront(const T& value)
{
	const auto temp = mHead;
	mHead = std::make_shared<Node<T>>(value, temp);
}

