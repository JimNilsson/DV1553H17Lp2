#include <vector>
#include <iostream>


void PrintVector(std::vector<int>& vec);

/*Sorterar en array genom att betrakta arrayen
  som tv� delar, en sorterad del och en osorterad del.
  Till en b�rjan �r den sorterade delen tom.
  S� l�nge det finns element kvar i den osorterade delen:
  -Ta det f�rsta elementet i den osorterade delen
  -Leta reda p� den plats i den sorterade araryen som detta element h�r hemma p�
  -S�tt in (d�rav insertion sort) elementet p� den platsen.
  Exempel:
  [|9, 6, 1, 5, 13, 4] // | �r avgr�nsaren mellan den sorterade och osorterade delen
  [9 | 6, 1, 5, 13, 4]
  [6, 9 | 1, 5, 13, 4]
  [1, 6, 9 | 5, 13, 4]
  [1, 5, 6, 9 | 13, 4]
  [1, 5, 6, 9, 13, | 4]
  [1, 4, 5, 6, 9, 13 |]
  */
void InsertionSort(std::vector<int>& vec);

/*Selection sort delar ocks� upp arrayen i ett sorterat omr�de
  och ett osorterat omr�de men fungerar lite annorlunda.
  S� l�nge som det finns element kvar i den osorterade delen:
  -Hitta det minsta elementet i den osorterade delen.
   (Man kan se det som att man 'v�ljer' det minsta elementet, d�rav selection sort.)
  -S�tt detta element i slutet p� den sorterade delen
  Exempel:
  [|9, 6, 1, 5, 13, 4] // 1 v�ljs som minsta element, byter plats med 9
  [1 | 6, 9, 5, 13, 4] //4 v�ljs som minsta element, byter plats med 6
  [1, 4 | 9, 5, 13, 6] // 5 v�ljs som minsta element, byter plats med 9
  [1, 4, 5 | 9, 13, 6] // 6 v�ljs som minsta element, byter plats med 9
  [1, 4, 5, 6 | 13, 9] // 9 v�ljs som minsta element, byter plats med 13
  [1, 4, 5, 6, 9 | 13] //Bara 13 finns kvar, arrayen �r sorterad
  */
void SelectionSort(std::vector<int>& vec);

int main()
{
	//srand(time(0));
	/*Vi anv�nder ett och samma seed f�r v�ra k�rningar i testsyfte*/
	srand(1234567);
	/*En vector �r en klassmall som "wrappar" en dynamiskt allokerad array
	  av den typ vi skickar in inom anglebrackets <>. Nedan skapar vi en 
	  vector av typen int. F�rdelen med detta �r att vi sj�lva slipper att
	*/
	std::vector<int> intVector;
	const int NUM_ITEMS = 10;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		intVector.push_back((rand() % 20) + 1);
	}

	std::cout << "Unsorted vector:\n";
	PrintVector(intVector);
	InsertionSort(intVector);
	std::cout << "\n\nSorted vector:\n";
	PrintVector(intVector);

	std::vector<int> intVector2;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		intVector2.push_back((rand() % 20) + 1);
	}

	std::cout << "\n\n\nUnsorted vector:\n";
	PrintVector(intVector2);
	SelectionSort(intVector2);
	std::cout << "\n\nSorted vector:\n";
	PrintVector(intVector2);


	std::cin.get();
	return 0;
}

void PrintVector(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
	}

	/* Range-baserade for-loopar introducerades i C++11 */
	//for (auto k : vec)
	//{
	//	std::cout << k << ", ";
	//}
}

void InsertionSort(std::vector<int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int indexOfFirstUnsorted = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (vec[indexOfFirstUnsorted] < vec[j])
			{
				std::swap(vec[indexOfFirstUnsorted], vec[j]);
				indexOfFirstUnsorted = j;
			}
			else
			{
				j = -1;
			}
		}
	}
}

void SelectionSort(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		int smallestIndex = i;
		for (int k = i + 1; k < vec.size(); k++)
		{
			if (vec[k] < vec[smallestIndex])
			{
				smallestIndex = k;
			}
		}
		std::swap(vec[smallestIndex], vec[i]);
	}
}
