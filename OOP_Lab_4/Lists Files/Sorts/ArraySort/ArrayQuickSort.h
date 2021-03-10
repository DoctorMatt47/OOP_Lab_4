#pragma once
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents quick sort of the array collection.
 * \tparam T Type of data, that is in the array collection.
 */
template <class T>
class ArrayQuickSort final : public IArraySort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

	/**
	 * \brief Additional function for Quick sort algorithm. 
	 * \param list Array collection to be sorted.
	 * \param low Bottom limit.
	 * \param high Top limit.
	 * \return Mid number.
	 */
	int Partition(IArrayCollection<T>& list, int low, int high);

	/**
	 * Quick sort recursive.
	 * \param list Array collection to be sorted.
	 * \param low Bottom limit.
	 * \param high Top limit.
	 */
	void QuickSortCore(IArrayCollection<T>& list, int low, int high);

public:
	/**
	* Constructs quick sort object.
	* \param comparePredicate Predicate used to compare elements at the array.
	*/
	explicit ArrayQuickSort(std::function<bool(T, T)> comparePredicate);

	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
int ArrayQuickSort<T>::Partition(IArrayCollection<T>& list, int low, int high)
{
	T pivot = list[high]; // pivot  
	auto i = (low - 1); // Index of smaller element  

	for (auto j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (_comparePredicate(pivot, list[j]))
		{
			i++; // increment index of smaller element  
			std::swap(list[i], list[j]);
		}
	}
	std::swap(list[i + 1], list[high]);
	return (i + 1);
}

template <class T>
void ArrayQuickSort<T>::QuickSortCore(IArrayCollection<T>& list, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		const int pi = Partition(list, low, high);

		// Separately sort elements before  
		// partition and after partition  
		QuickSortCore(list, low, pi - 1);
		QuickSortCore(list, pi + 1, high);
	}
}

template <class T>
ArrayQuickSort<T>::ArrayQuickSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void ArrayQuickSort<T>::Execute(IArrayCollection<T>& list)
{
	if (list.GetSize() > 1)
		QuickSortCore(list, 0, list.GetSize() - 1);
}