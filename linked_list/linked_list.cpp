
#include <memory>

template<typename T>
class LinkedList {
public:
	LinkedList() : mHead(nullptr) {}

	LinkedList& add(const T value)
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

	std::shared_ptr& search(const T& value)
	{
		std::shared_ptr<Node<T>> p = mHead;
		while (p->mNext != nullptr && p->mNext)
		{
			p = p->mNext;
		}
		if (p != nullptr)
		{
			return p->mValue;
		}
		else
		{
			return nullptr;
		}
	}

	void removefromlist(const T& value)
	{
		std::shared_ptr<Node<T>> p = mHead;
		std::shared_ptr<Node<T>> e = nullptr;

		if (search(value) != nullptr)
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
	std::shared_ptr<Node<T>> _head;

	template<typename T>
	struct Node
	{
		Node(const T& value) : mValue(value) {}
		T mValue;
		std::shared_ptr<Node> mNext = nullptr;
	};
};