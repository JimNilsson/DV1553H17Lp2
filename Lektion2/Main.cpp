#include "FriendBook.h"
#include "Friend.h"
#include <iostream>
#include <string>

void DynamicArrayExamples();
void ExceptionExample();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//DynamicArrayExamples();

	ExceptionExample();

	FriendBook fb;
	fb.AddFriend("Olle", 94, 2, 13);
	fb.AddFriend("Lisa", 84, 4, 30);
	fb.AddFriend("Karl", 90, 2, 5);

	if (fb.AddFriend("Olle", 94, 2, 13) == false)
		std::cout << "You already have a friend with that name, one is enough.\n";

	std::cout << fb.ToString();

	std::cout << "Saving to file: friends.txt\n";
	fb.SaveToFile("friends.txt");
	
	std::cout << "Clearing friendbook.\n";
	fb.Clear();

	std::cout << "Reading from file and saving in friendbook.\n";
	fb.ReadFromFile("friends.txt");
	std::cout << "Printing friends that were read from file.\n";
	std::cout << fb.ToString();


	std::cin.get();
	return 0;//Destructor of object 'fb' is called. The program leaves the scope the object was created in.
} 

void DynamicArrayExamples()
{
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
}

void ExceptionExample()
{
	Friend a("Kalle");
	try
	{
		a.SetBirthDateYear(300);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
