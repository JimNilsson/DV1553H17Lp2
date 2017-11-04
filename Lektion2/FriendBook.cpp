#include "FriendBook.h"
#include <fstream>

FriendBook::FriendBook()
{
	count = 0;
	capacity = 2;
	friends = new Friend*[capacity];
}

FriendBook::~FriendBook()
{
	for (int i = 0; i < count; i++)
	{
		delete friends[i];
	}
	delete[] friends;
}

bool FriendBook::AddFriend(const std::string& name, int year, int month, int day)
{
	Friend toAdd(name, day, month, year);
	int index = FindFriend(toAdd);
	if (index == -1)
	{
		if (count == capacity)
		{
			Expand();
		}
		friends[count++] = new Friend(toAdd);
	}
	return index == -1;
}

void FriendBook::Expand()
{
	capacity = capacity * 2;
	Friend** temp = new Friend*[capacity];
	for (int i = 0; i < count; i++)
	{
		temp[i] = friends[i];
	}
	delete[] friends;
	friends = temp;
}

bool FriendBook::RemoveFriend(const std::string& name)
{
	Friend toRemove(name);
	int index = FindFriend(toRemove);
	if (index != -1)
	{
		delete friends[index];
		friends[index] = friends[--count];
		friends[count] = nullptr;
	}
	return index != -1;
}

int FriendBook::FindFriend(const Friend& f) const
{
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (f == *friends[i])
		{
			index = i;
			i = count;
		}
	}
	return index;
}

std::string FriendBook::ToString() const
{
	std::string retString = "";
	for (int i = 0; i < count; i++)
	{
		retString += friends[i]->ToString();
	}
	return retString;
}

int FriendBook::GetSize() const
{
	return count;
}


void FriendBook::ReadFromFile(const std::string& filename)
{
	std::ifstream fileIn(filename);
	if (fileIn.is_open())
	{
		int friendsInFile;
		std::string tempName;
		int tempYear;
		int tempMonth;
		int tempDay;

		fileIn >> friendsInFile;
		fileIn.ignore();
		for (int i = 0; i < friendsInFile; i++)
		{
			std::getline(fileIn, tempName);
			fileIn >> tempYear; fileIn.ignore();
			fileIn >> tempMonth; fileIn.ignore();
			fileIn >> tempDay; fileIn.ignore();
			AddFriend(tempName, tempYear, tempMonth, tempDay);
		}
	}
}


void FriendBook::SaveToFile(const std::string& filename) const
{
	std::ofstream fileOut(filename);
	if (fileOut.is_open())
	{
		fileOut << count << std::endl;
		for (int i = 0; i < count; i++)
		{
			fileOut << friends[i]->GetName() << std::endl;
			fileOut << friends[i]->GetBirthDateYear() << std::endl;
			fileOut << friends[i]->GetBirthDateMonth() << std::endl;
			fileOut << friends[i]->GetBirthDateDay() << std::endl;
		}
	}
}


void FriendBook::Clear()
{
	for (int i = 0; i < count; ++i)
	{
		delete friends[i];
	}
	count = 0;
}