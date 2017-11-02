#include "Friend.h"
#include <iostream>
#include <string>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int capacity;
	int nrOfFriends = 0;
	std::cout << "Enter capacity: ";
	std::cin >> capacity;
	std::cin.ignore();
	Friend** friendPtrs = new Friend*[capacity];

	while (nrOfFriends != capacity)
	{
		std::string name;
		std::cout << "Enter name: ";
		getline(std::cin, name);
		friendPtrs[nrOfFriends++] = new Friend(name);
	}

	for (int i = 0; i < nrOfFriends; i++)
	{
		std::cout << friendPtrs[i]->ToString();
		//std::cout << (*friendPtrs[i]).ToString();
	}

	std::cout << "How many more to add?\n";
	int extra;
	std::cin >> extra;
	std::cin.ignore();

	//Expandering
	capacity += extra;
	Friend** temp = new Friend*[capacity];
	for (int i = 0; i < nrOfFriends; i++)
	{
		temp[i] = friendPtrs[i];
	}
	delete[] friendPtrs;
	friendPtrs = temp;

	while (nrOfFriends != capacity)
	{
		std::string name;
		std::cout << "Enter name: ";
		getline(std::cin, name);
		friendPtrs[nrOfFriends++] = new Friend(name);
	}

	//Djupkopiering av array av pekare
	Friend** copyOfFriends = new Friend*[capacity];
	for (int i = 0; i < nrOfFriends; i++)
	{
		copyOfFriends[i] = new Friend(*friendPtrs[i]);
	}

	//Avallokering
	for (int i = 0; i < nrOfFriends; i++)
	{
		delete friendPtrs[i];
	}
	delete[] friendPtrs;

	for (int i = 0; i < nrOfFriends; i++)
	{
		delete copyOfFriends[i];
	}
	delete[] copyOfFriends;

	std::cin.get();
	return 0;
}