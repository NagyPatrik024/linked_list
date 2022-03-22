#include "node.h"
template<typename T>
struct Node
{
	Node(const T value) : _value(value), _next(nullptr) {}

	T _value;
	std::shared_ptr<Node> _next;
};
