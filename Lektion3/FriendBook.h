#ifndef FRIENDBOOK_H
#define FRIENDBOOK_H

#include "Friend.h"

class FriendBook
{
public:
	FriendBook();
	~FriendBook();

	/* Kopieringskonstruktor och tilldelningsoperator skapas implicit av kompilatorn, problemet med detta
	 * är att de av kompilatorn genererade kopieringskonstruktor och tilldelningsoperator endast utför
	 * en "memberwise copy"/"shallow copy"/ytkopiering av objekten. Därför måste vi överlagra dessa
	 * när vi har en klass med pekare till dynamiskt allokerat minne.
	*/

	//Copy-konstruktor.
	/*Observa const i parameterlistan! Vi skickar objektet som en referens för att slippa göra en kopia.
	 * const ser till så att vi inte av misstag kan råka ändra i objektet other.*/
	FriendBook(const FriendBook& other);
	//Tilldelningsoperator/assignment operator
	/*Notera returtyp FriendBook&. Se main.cpp för förklaring om varför.*/
	FriendBook& operator=(const FriendBook& other);

	bool AddFriend(const std::string& name, int year, int month, int day);
	bool RemoveFriend(const std::string& name);

	//Returnerar en strängrepresentation av samtliga friends
	std::string ToString() const;

	bool GetFriendsAsStrings(std::string* arr, int capOfArr) const;
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
