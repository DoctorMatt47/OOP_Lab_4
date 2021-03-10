#pragma once
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents selection sort of the array collection.
 * \tparam T Type of data, that is in the array collection.
 */
template <class T>
class ArraySelectionSort final : public IArraySort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

public:
	/**
	* Constructs selection sort object.
	* \param comparePredicate Predicate used to compare elements at the array.
	*/
	explicit ArraySelectionSort(std::function<bool(T, T)> comparePredicate);

	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
ArraySelectionSort<T>::ArraySelectionSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void ArraySelectionSort<T>::Execute(IArrayCollection<T>& list)
{
	// One by one move boundary of unsorted subarray.
	for (auto i = 0; i < list.GetSize() - 1; i++)
	{
		// Find the minimum element in unsorted array . 
		auto minIdx = i;
		for (auto j = i + 1; j < list.GetSize(); j++)
			if (_comparePredicate(list[minIdx], list[j]))
				minIdx = j;

		// Swap the found minimum element with the first element . 
		std::swap(list[minIdx], list[i]);
	}
}