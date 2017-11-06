#include "FriendBook.h"
#include "Friend.h"
#include <iostream>
#include <string>

void PrintFriends(FriendBook& fb);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	FriendBook fb1;
	fb1.AddFriend("Kalle", 92, 2, 16);
	fb1.AddFriend("Olle", 91, 5, 12);


	//Implicit anrop av kopieringskonstruktor
	FriendBook fb2 = fb1;

	std::cout << "Contents of fb1...\n";
	std::cout << fb1.ToString() << "\n";
	std::cout << "Contents of fb2...\n";
	std::cout << fb2.ToString() << "\n\n";

	fb1.RemoveFriend("Kalle");
	std::cout << "Contents of fb1...\n";
	std::cout << fb1.ToString() << "\n";
	std::cout << "Contents of fb2...\n";
	std::cout << fb2.ToString() << "\n\n";

	FriendBook fb3(fb2); //Anropar kopieringskonstruktor
	FriendBook fb4 = FriendBook(fb2); //Anropar också kopieringskonstruktor

	fb2 = fb1; //Anropar tilldelningsoperator.
	fb2 = fb2; //Se till att detta inte orsakar problem!

	//Går även att "kedja ihop" flera assignments tack vare att returtypen är FriendBook&
	fb1 = fb2 = fb3;
	//Detta är ekvivalent med:
	fb1.operator=(fb2.operator=(fb3));
	//Den "innersta" tilldelningen görs först, d.v.s. fb2 = fb3


	PrintFriends(fb1);
	PrintFriends(fb2);
	PrintFriends(fb3);
	PrintFriends(fb4);
	
	std::cin.get();
	return 0;
} 

void PrintFriends(FriendBook & fb)
{
	int numFriends = fb.GetSize();
	std::string* stringArr = new std::string[numFriends];
	fb.GetFriendsAsStrings(stringArr, numFriends);
	std::cout << "Printing friends...\n";
	for (int i = 0; i < numFriends; i++)
	{
		std::cout << stringArr[i];
	}
	delete[] stringArr;
}
