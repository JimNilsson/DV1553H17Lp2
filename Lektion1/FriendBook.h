#ifndef FRIENDBOOK_H
#define FRIENDBOOK_H

#include "Friend.h"

class FriendBook
{
public:
	static const int CAP = 10;
	Friend friends[CAP];

	FriendBook();
	~FriendBook();

	//Tv� �verlagringar av metoden AddFriend
	bool AddFriend(const std::string& name, int year, int month, int day);
	bool RemoveFriend(const std::string& name);
	
	//Returnerar en str�ngrepresentation av samtliga friends
	std::string ToString() const;
	//Returnerar antalet inlagda friends
	int GetSize() const;

	//L�ser in friend-objekt fr�n fil och sparar i arrayen friends
	void ReadFromFile(const std::string& filename);

	//Sparar alla friend-objekt p� fil
	void SaveToFile(const std::string& filename) const; //Obs. const

	//"Tar bort" alla friends i FriendBook
	void Clear();


private:
	int count;
	int FindFriend(const Friend& f) const;
};

#endif
