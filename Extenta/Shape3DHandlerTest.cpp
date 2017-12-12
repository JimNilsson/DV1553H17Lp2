#include "Shape3DHandler.h"
#include <iostream>
#include <algorithm> //std::min

void PrintHandler(Shape3DHandler& sh)
{
	int nrOf = sh.GetNrOfShapes();
	std::string* arr = new std::string[nrOf];
	sh.GetAll(arr, nrOf);
	for (int i = 0; i < nrOf; i++)
	{
		std::cout << arr[i] << "\n";
	}
	delete[] arr;
}

//Snabbt test med throw-try-catch, ej del av uppgiften
void DoThing(int a)
{
	if (a < 0)
		throw std::exception("a may not be negative");
}

int main()
{
	try {
		DoThing(-1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what(); 
	}
	std::cin.get();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 154;
	Shape3DHandler sh;
	sh.AddBox(1, 1, 1);
	sh.AddBox(2, 2, 2);
	//Testar expandering...
	sh.AddCone(2, 4);
	sh.AddBox(2, 3, 4);

	std::string strArr[4];
	sh.GetAll(strArr, 4);
	for (int i = 0; i < 4; i++)
	{
		std::cout << strArr[i] << "\n";
	}
	std::cin.get();
	std::cout << "Removing boxes...\n\n";
	sh.RemoveBox(2, 3, 4);
	sh.RemoveBox(1, 1, 1);
	std::string strArr2[10];
	sh.GetAll(strArr2, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << strArr2[i] << "\n";
	}

	std::cin.get();
	std::cout << "Testing cctor and operator=...\n\n";
	Shape3DHandler sh2 = sh;
	PrintHandler(sh2);
	std::cin.get();
	Shape3DHandler sh3;
	sh3.AddBox(5, 5, 5);
	sh = sh3;
	PrintHandler(sh);
	std::cin.get();
	return 0;
}