#pragma once
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents insertion sort of the array collection.
 * \tparam T Type of data, that is in the array collection.
 */
template <class T>
class ArrayInsertionSort final : public IArraySort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

public:
	/**
	* Constructs insertion sort object.
	* \param comparePredicate Predicate used to compare elements at the array.
	*/
	explicit ArrayInsertionSort(std::function<bool(T, T)> comparePredicate);

	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
ArrayInsertionSort<T>::ArrayInsertionSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void ArrayInsertionSort<T>::Execute(IArrayCollection<T>& list)
{
	for (auto i = 1; i < list.GetSize(); i++)
	{
		T key = list[i];
		auto j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && _comparePredicate(list[j], key))
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}