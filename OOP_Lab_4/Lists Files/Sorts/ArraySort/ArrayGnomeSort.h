#pragma once
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

template <class T>
class ArrayGnomeSort final : public IArraySort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;
	
public:
	explicit ArrayGnomeSort(std::function<bool(T, T)> comparePredicate);
	
	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
ArrayGnomeSort<T>::ArrayGnomeSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void ArrayGnomeSort<T>::Execute(IArrayCollection<T>& list)
{
	auto index = 0;

	while (index < list.GetSize())
	{
		if (index == 0)
			index++;
		if (_comparePredicate(list[index], list[index - 1]))
			index++;
		else
		{
			std::swap(list[index], list[index - 1]);
			index--;
		}
	}
}
