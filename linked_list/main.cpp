#include <iostream>
#include "linked_list.cpp"
#include <string>

struct Student
{
	std::string mName;
	uint8_t mAge;


};

int main()
{

	LinkedList<Student> liStudent;
	liStudent.AddFront(Student{ "Sarah Student",19 });
	liStudent.AddFront(Student{ "Steve Student",23 });

	const int age = 20;
	const auto isYounger = [age](const Student& student) { return student.mAge < age; };

	liStudent.Search(isYounger);

	liStudent.Traverse([](const auto& student) { std::cout << student.mName << " " << std::to_string(student.mAge) << std::endl; });
	LinkedList<int> li;

	li.AddFront(3);
	li.AddBack(5);
	li.AddFront(1);

	const auto isOdd = [](const int value) { return value % 2 != 0; };

	if (li.Search(isOdd))
	{
		std::cout << "Van ilyen" << std::endl;
	}

	li.Traverse([](const int value) {std::cout << std::to_string(value) << std::endl; });
}