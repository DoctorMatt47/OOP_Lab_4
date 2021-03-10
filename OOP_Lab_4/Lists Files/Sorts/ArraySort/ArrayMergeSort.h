#pragma once
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents merge sort of the array collection.
 * \tparam T Type of data, that is in the array collection.
 */
template <class T>
class ArrayMergeSort final : public IArraySort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

	/**
	 * Merges two subarrays. 
	 * \param list Array collection to be sorted.
	 * \param low Bottom limit.
	 * \param mid Middle element.
	 * \param high Top limit.
	 */
	void MergeCore(IArrayCollection<T>& list, int low, int mid, int high);

	/**
	 * Merge sort recursive algorithm.
	 * \param list Array collection to be sorted.
	 * \param low Bottom limit.
	 * \param high Top limit.
	 */
	void MergeSortCore(IArrayCollection<T>& list, int low, int high);

public:
	/**
	* Constructs quick sort object.
	* \param comparePredicate Predicate used to compare elements at the array.
	*/
	explicit ArrayMergeSort(std::function<bool(T, T)> comparePredicate);

	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
void ArrayMergeSort<T>::MergeCore(IArrayCollection<T>& list, int low, int mid, int high)
{
	int i, j;
	auto n1 = mid - low + 1;
	auto n2 = high - mid;

	/* create temp arrays */
	T* l = new T[n1];
	T* r = new T[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		l[i] = list[low + i];
	for (j = 0; j < n2; j++)
		r[j] = list[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	auto k = low; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (_comparePredicate(r[j], l[i]))
		{
			list[k] = l[i];
			i++;
		}
		else
		{
			list[k] = r[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		list[k] = l[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		list[k] = r[j];
		j++;
		k++;
	}

	delete[] l;
	delete[] r;
}

template <class T>
void ArrayMergeSort<T>::MergeSortCore(IArrayCollection<T>& list, int low, int high)
{
	if (low < high)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		auto m = low + (high - low) / 2;

		// Sort first and second halves 
		MergeSortCore(list, low, m);
		MergeSortCore(list, m + 1, high);

		MergeCore(list, low, m, high);
	}
}

template <class T>
ArrayMergeSort<T>::ArrayMergeSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void ArrayMergeSort<T>::Execute(IArrayCollection<T>& list)
{
	MergeSortCore(list, 0, list.GetSize() - 1);
}