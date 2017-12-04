#include <iostream>
#include <string>
#include "Functions.h"
#include "MyVector.h"

template <typename T>
void printArr(T* arr, int nrOfItems)
{
	for (int i = 0; i < nrOfItems; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\n";
}

int main()
{
	int a = 3;
	int b = 5;
	swapThem(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";

	int intArr[] = { 3, 10, 12, 5, 1, 17 };
	printArr(intArr, 6); 
	selectionSort(intArr, 6);
	printArr(intArr, 6);

	std::string strArr[] = { "abc", "ghi", "efg", "mno" };
	printArr(strArr, 4);
	selectionSort(strArr, 4);
	printArr(strArr, 4);

	MyVector<std::string> stringVec;
	MyVector<float> floatVec;

	floatVec.AddAtEnd(2.0f);
	std::cout << floatVec.GetAtIndex(0) << "\n";

	stringVec.AddAtEnd("ABC 123");
	std::cout << stringVec.GetAtIndex(0) << "\n";
	std::cin.get();
	return 0;
}
