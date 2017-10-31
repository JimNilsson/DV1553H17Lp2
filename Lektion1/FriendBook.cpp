#include "FriendBook.h"
#include <fstream>

FriendBook::FriendBook()
{
	count = 0;
}

FriendBook::~FriendBook()
{
	//Empty
}

bool FriendBook::AddFriend(const std::string & name, int year, int month, int day)
{
	bool ret = false;
	if (count < CAP)
	{
		Friend toCompare = Friend(name, day, month, year);
		if (FindFriend(toCompare) == -1)
		{
			friends[count].SetName(name);
			if (friends[count].SetBirthDateDay(day) &&
				friends[count].SetBirthDateMonth(month) &&
				friends[count].SetBirthDateYear(year))
			{
				//Om alla set-funktioner lyckades ökar vi count
				++count;
				ret = true;
			}
		}
	}
	return ret;
}

bool FriendBook::RemoveFriend(const std::string & name)
{
	int index = FindFriend(Friend(name));
	if (index != -1)
	{
		friends[index] = friends[--count];
	}
	return index != -1;
}

std::string FriendBook::ToString() const
{
	std::string retString = "";
	for (int i = 0; i < count; i++)
	{
		retString += friends[i].ToString();
	}
	return retString;
}

int FriendBook::GetSize() const
{
	return count;
}

void FriendBook::ReadFromFile(const std::string & filename)
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
		if (friendsInFile + count < CAP)
		{
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
}

void FriendBook::SaveToFile(const std::string & filename) const
{
	std::ofstream fileOut(filename);
	if (fileOut.is_open())
	{
		fileOut << count << std::endl;
		for (int i = 0; i < count; i++)
		{
			fileOut << friends[i].GetName() << std::endl;
			fileOut << friends[i].GetBirthDateYear() << std::endl;
			fileOut << friends[i].GetBirthDateMonth() << std::endl;
			fileOut << friends[i].GetBirthDateDay() << std::endl;
		}
	}
}

void FriendBook::Clear()
{
	count = 0;
}

int FriendBook::FindFriend(const Friend & f) const
{
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (friends[i] == f)
		{
			index = i;
			i = count;
		}
	}
	return index;
}

