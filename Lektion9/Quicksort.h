#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <algorithm> //std::swap
template <typename T>
int Partition(T* arr, int start, int end)
{
	int pivot = start;
	T value = arr[pivot];
	for(int i = start + 1; i <= end; i++)
	{
		if(arr[i] < value)
		{
			std::swap(arr[i], arr[pivot + 1]);
			std::swap(arr[pivot], arr[pivot + 1]);
			pivot++;
		}
	}
	return pivot;
}

template <typename T>
void Quicksort(T* arr, int start, int end)
{
	if(start < end) //V�rt "stop condition". Rekursionen avslutas n�r start == end
	{
		int pivot = Partition(arr, start, end);
		Quicksort(arr, start, pivot - 1); //G�r samma sak p� "v�nstra" delen
		Quicksort(arr, pivot + 1, end); //G�r samma sak p� "h�gra" delen
	}
}

#endif

