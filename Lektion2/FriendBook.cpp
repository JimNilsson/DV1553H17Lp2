#include "FriendBook.h"

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