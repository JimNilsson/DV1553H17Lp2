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

FriendBook::FriendBook(const FriendBook & other)
{
	/* Kopieringskontruktorn anropas n�r vi skapar ett nytt objekt som en kopia av ett annat objekt. Exempelvis:
	 * FriendBook fb2(fb1);
	 * FriendBook fb3 = fb1;
	 * FriendBook fb4 = FriendBook(fb1);
	 * I samtliga av fallen ovan s� anropas kopieringskontruktorn.
	*/
	this->count = other.count;
	this->capacity = other.capacity;
	this->friends = new Friend*[this->capacity];
	for (int i = 0; i < this->count; i++)
	{
		/*Om en klass inneh�ller pekare till dynamiskt allokerat minne s� m�ste vi �verlagra kopieringskonstruktor och tilldelningsoperator
		* f�r att se till att kopieringen g�r till p� korrekt s�tt.
		*/
		this->friends[i] = new Friend(*other.friends[i]);
	}
}

FriendBook & FriendBook::operator=(const FriendBook & other)
{
	/* Sj�lvtilldelningskontroll. G�r s� att inget g�r fel om man r�kar g�ra en sj�lvtilldelning.
	 * Exempelvis: fb = fb;
	 * this �r som bekant en pekare (d.v.s. adress) till "detta" objekt. Vi j�mf�r denna adress med adressen f�r objektet "other".
	 * Om dessa adresser �r samma s� betyder det att en tilldelning i stil med fb = fb har gjorts. En s�dan tilldelning ska inte ha n�gon effekt. D�rav denna kontroll.
	 */
	if (this != &other)
	{
		/* Eftersom tilldelningsoperatorn anropas n�r objektet som this pekar p� redan existerar s� betyder det att detta objekt har allokerat minne.
		 * Detta minne m�ste avallokeras innan vi kan utf�ra kopieringen, i annat fall r�kar vi ut f�r en minnesl�cka.
		 * Betrakta f�ljande exempel:
		 * FriendBook fb1; //Konstruktorn anropas, en array allokeras
		 * fb1.AddFriend("Blah", 84, 2, 17); //Ett Friend-objekt allokeras.
		 * FriendBook fb2;
		 * fb2.AddFriend("Bluh", 92, 5, 15);
		 * fb1 = fb2; //fb1 existerar sedan tidigare, det minne som fb1 har allokerat m�ste avallokeras innan vi utf�r djupkopiering fr�n fb2 till fb1.
		*/
		for (int i = 0; i < this->count; i++)
		{
			delete this->friends[i];
		}
		delete[] this->friends;

		/* Resten av kopieringen utf�rs p� samma s�tt som i kopieringskonstruktorn. */
		this->count = other.count;
		this->capacity = other.capacity;
		this->friends = new Friend*[this->capacity];
		for (int i = 0; i < this->count; i++)
		{
			this->friends[i] = new Friend(*other.friends[i]);
		}
	}

	return *this;
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

bool FriendBook::GetFriendsAsStrings(std::string * arr, int capOfArr) const
{
	bool ret = false;
	if (capOfArr >= this->count)
	{
		ret = true;
		for (int i = 0; i < count; i++)
		{
			arr[i] = friends[i]->ToString();
		}
	}
	return ret;
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