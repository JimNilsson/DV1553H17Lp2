#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector
{
private:
	T* arr;
	int cap;
	int count;
	void Expand();
public:
	MyVector();
	~MyVector();

	void AddAtEnd(const T& item);
	T GetAtIndex(int index);

	//Övning
	bool Remove(const T& item);
	T& operator[](size_t index);
};


#endif

template<typename T>
inline void MyVector<T>::Expand()
{
	cap += 5;
	T* temp = new T[cap];
	for (int i = 0; i < count; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

template<typename T>
inline MyVector<T>::MyVector()
{
	cap = 5;
	count = 0;
	arr = new T[cap];
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	delete[] arr;
}

template<typename T>
inline void MyVector<T>::AddAtEnd(const T & item)
{
	if (count == cap)
		Expand();
	arr[count++] = item;
}

template<typename T>
inline T MyVector<T>::GetAtIndex(int index)
{
	if (index > count)
		throw std::exception("Invalid index");
	return arr[index];
}
