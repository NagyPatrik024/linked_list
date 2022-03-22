#include <memory>
#include <functional>

template<typename T>
class LinkedList {
private:
	struct Node
	{
		Node(const T& value) : mValue(value) {}
		Node(const T& value, const std::shared_ptr<Node> next) : mValue(value), mNext(next) {}

		T mValue;
		std::shared_ptr<Node> mNext = nullptr;
	};

public:
	LinkedList() = default;


	void AddFront(const T& value);
	void AddBack(const T& value);
	const std::shared_ptr<Node> Contains(const T& value) const;
	bool Search(const std::function<bool(const T&)>& predicate) const;
	void Traverse(const std::function<void(const T&)>& execute) const;



private:
	std::shared_ptr<Node> mHead = nullptr;
};

template<typename T>
void LinkedList<T>::Traverse(const std::function<void(const T&)>& execute) const
{
	auto p = mHead;
	while (p != nullptr)
	{
		execute(p->mValue);
		p = p->mNext;
	}
}

template<typename T>
bool LinkedList<T>::Search(const std::function<bool(const T&)>& predicate) const
{
	std::shared_ptr<Node> p = mHead;
	while (p != nullptr && !predicate(p->mValue))
	{
		p = p->mNext;
	}

	return p != nullptr;
}

template<typename T>
const std::shared_ptr<typename LinkedList<T>::Node> LinkedList<T>::Contains(const T& value) const
{
	std::shared_ptr<Node> p = mHead;
	while (p != nullptr && p->mValue != value)
	{
		p = p->mNext;
	}
	return p;

}

template<typename T>
void LinkedList<T>::AddBack(const T& value)
{
	if (!mHead)
	{
		mHead = std::make_shared<Node>(value);
	}
	else
	{
		std::shared_ptr<Node> p = mHead;
		while (p->mNext)
		{
			p = p->mNext;
		}
		p->mNext = std::make_shared<Node>(value);
	}
}

template<typename T>
void LinkedList<T>::AddFront(const T& value)
{
	const auto temp = mHead;
	mHead = std::make_shared<Node>(value, temp);
}

#pragma once
