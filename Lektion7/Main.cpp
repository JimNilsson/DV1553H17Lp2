#include "Triangle.h"
#include "Square.h"
#include <iostream>

int main()
{
	srand(500);
	

	//Shape är abstrakt. VI kan inte skapa en instans av denna klass.
	//Shape p; //Kompilerar inte, ty p är abstrakt.

	//Vi kan dock ha pekare av denna typ
	Shape* baseArray[5];
	for (int i = 0; i < 5; ++i)
	{
		if (rand() % 2 == 0)
			baseArray[i] = new Triangle("Blue", 20, 10);
		else
			baseArray[i] = new Square("Red", 10);
	}


	//Polymorfism...
	for (int i = 0; i < 5; i++)
	{
		//Pekaren är av typen Shape, objekten är av typerna Triangle och Square, men vi kan använda dem som om de vore av typen Shape!
		baseArray[i]->Draw();
	}

	//Dynamic_cast... Behövs för att komma åt subklassernas _egna_ medlemsfunktioner.
	for (int i = 0; i < 5; i++)
	{
		//Type inference, nytt i C++11, (eller var det C++14?)
		auto trianglePtr = dynamic_cast<Triangle*>(baseArray[i]);
		//Går också skriva: Triangle* trianglePtr = dynamic_cast<Triangle*>(baseArray[i]);
		if (trianglePtr != nullptr)
		{
			std::cout << "Calling triangle's own function...\n";
			trianglePtr->SpecialTriangleThing(); //trianglePtr är av typen Triangle*, därav kommer vi åt SpecialTriangleThing
		}
	}


	//Typeid...
	if (typeid(*baseArray[0]) == typeid(Square))
	{
		std::cout << "We have a Square!\n";
	}
	else
	{
		std::cout << "We have a Triangle!\n";
	}




	for (int i = 0; i < 5; i++)
	{
		delete baseArray[i];
	}
	std::cin.get();
	return 0;
}