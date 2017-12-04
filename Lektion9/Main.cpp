#include "Student.h"
#include <iostream>

#include "Quicksort.h"

void RecursiveFunction(int nr)
{
	std::cout << "RecursiveFunction anropas med nr = " << nr << "\n";
	if(nr > 0)
	{
		RecursiveFunction(nr - 1);
	}
	std::cout << "RecursiveFunction lämnas med nr = " << nr << "\n";
}

int main()
{
	
	Student kalle("Kalle Kallesson", 3);

	std::cout << kalle;
	std::cin.get();

	RecursiveFunction(5);
	std::cin.get();

	int values[10] = { 1, 5, 2, 7, 2, 13, 44, 22, 144, 13 };
	Quicksort(values, 0, 9); //Obs: end är sista indexet, inte antal element
	for(int i = 0; i < 10; i++)
	{
		std::cout << values[i] << ", ";
	}
	std::cin.get();

	return 0;
}