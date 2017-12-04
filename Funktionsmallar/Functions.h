#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

template <typename T>
void swapThem(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
int findMin(T* arr, int startIndex, int endIndex)
{
	int minIndex = startIndex;
	for (int i = startIndex + 1; i < endIndex; i++)
	{
		if (arr[i] < arr[minIndex])
			minIndex = i;
	}
	return minIndex;
}

template <typename T>
void selectionSort(T* arr, int nrOfItems)
{
	int minIndex = 0;
	for (int i = 0; i < nrOfItems - 1; i++)
	{
		minIndex = findMin(arr, i, nrOfItems);
		swapThem(arr[i], arr[minIndex]);
	}
}

#endif
