#ifndef FRIENDBOOK_H
#define FRIENDBOOK_H

#include "Friend.h"

class FriendBook
{
public:
	FriendBook();
	~FriendBook();

	bool AddFriend(const std::string& name, int year, int month, int day);
	bool RemoveFriend(const std::string& name);

	//Returnerar en strängrepresentation av samtliga friends
	std::string ToString() const;
	//Returnerar antalet inlagda friends
	int GetSize() const;

	//Läser in friend-objekt från fil och sparar i arrayen friends
	void ReadFromFile(const std::string& filename);

	//Sparar alla friend-objekt på fil
	void SaveToFile(const std::string& filename) const; //Obs. const

	//"Tar bort" alla friends i FriendBook
	void Clear();

private:
	int count;
	int capacity;
	Friend** friends;
	int FindFriend(const Friend& f) const;
	void Expand();
};

#endif
