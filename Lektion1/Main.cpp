
#include <iostream>
#include "FriendBook.h"

int main(int argc, char** argv)
{
	FriendBook fb;

	//Några tester...

	//Lägga till vänner
	fb.AddFriend("Kalle", 85, 2, 17);
	fb.AddFriend("Olle", 92, 5, 11);
	fb.AddFriend("Lisa", 90, 9, 24);

	//Skriva ut
	std::cout << fb.ToString();

	//Lägga till vän som redan finns
	if (!fb.AddFriend("Lisa", 90, 9, 24))
	{
		std::cout << "Friend already exists.\n";
	}

	//Skriv ut och kolla att inget lades till
	std::cout << fb.ToString();

	//Prova ta bort
	if (fb.RemoveFriend("Olle"))
		std::cout << "Olle togs bort\n";

	std::cout << fb.ToString();




	std::cin.get();
	return 0;
}