#include "Location.h"
#include "City.h"
#include <iostream>


int main()
{
	srand(100);

	for (int i = 0; i < 10; i++)
	{
		std::cout << rand() % 12 + 1 << ", ";
	}
	std::cin.get();
	Location l(56.18, 15.82, "Karlskrona");


	float longitude, latitude;
	l.GetLocation(longitude, latitude);
	std::cout << "Longitude: " << longitude << "\n";
	std::cout << "Latitude: " << latitude << "\n\n";

	Location* lp = new City(56.18, 14.78, "Karlshamn", 19000, 20);
	City* cityPtr = new City(56.18, 15.82, "Karlskrona", 35000, 30);

	std::cout << lp->ToString();
	std::cout << cityPtr->ToString();

	cityPtr->SetPopulation(20000);
	//lp->SetPopulation(3000); //Går inte, behållaren är av fel typ.
	
	  
	delete lp;
	delete cityPtr;
	std::cin.get();
	return 0;
}