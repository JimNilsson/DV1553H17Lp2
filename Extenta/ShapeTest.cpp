//#include "Box.h"
//#include "Cone.h"
//#include <iostream>
//#include <ctime>
//
//
//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	srand(time(0));
//
//	Shape3D* arr[5] = {};
//	arr[0] = new Cone(2.0f, 1.0f);
//	arr[1] = new Box(2.0f, 2.0f, 2.0f);
//	arr[2] = new Cone(4.0f, 2.0f);
//	arr[3] = new Box(1.0f, 1.0f, 1.0f);
//
//	for (int i = 0; i < 4; i++)
//	{
//		std::cout << "Volume: " << arr[i]->GetVolume() << "\n";
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		int index1 = rand() % 4;
//		int index2 = rand() % 4;
//		std::swap(arr[index1], arr[index2]);
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		Cone* conePtr = dynamic_cast<Cone*>(arr[i]);
//		if (conePtr != nullptr)
//		{
//			conePtr->SetRadius(5.0f);
//		}
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		if (typeid(Cone) == typeid(*arr[i]))
//		{
//			std::cout << "Volume: " << arr[i]->GetVolume() << "\n";
//		}
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		delete arr[i];
//	}
//
//
//
//	std::cin.get();
//}
