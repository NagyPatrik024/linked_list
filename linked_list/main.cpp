#include <iostream>
#include "linked_list.cpp"

int main()
{
	LinkedList<int> li;

	li.AddFront(3);
	li.AddBack(5);
	li.AddFront(1);

	if (li.Search([](const int value) { return value % 2 != 0; }))
	{
		std::cout << "Van ilyen" << std::endl;
	}
}