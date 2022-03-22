
#include <memory>

template<typename T>
class LinkedList {
	LinkedList();

	LinkedList& add(const T value);
	std::shared_ptr& search(const T& value);
	void removefromlist(const T& value);
	
private:
	std::shared_ptr<Node<T>> mHead;
	template<typename T>
	struct Node;
};