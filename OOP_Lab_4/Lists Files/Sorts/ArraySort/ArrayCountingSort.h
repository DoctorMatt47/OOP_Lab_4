#pragma once
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents counting sort of the array collection.
 * \tparam T Type of data, that is in the array collection.
 */
template <class T>
class ArrayCountingSort final : public IArraySort<T>
{
private:
	std::function<size_t(T)> _sortField;

public:
	/**
	* Constructs counting sort object.
	* \param sortField Function returns field which used to compare elements at the list.
	* This field must be an integer and not negative.
	*/
	explicit ArrayCountingSort(std::function<size_t(T)> sortField);

	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
ArrayCountingSort<T>::ArrayCountingSort(std::function<size_t(T)> sortField)
{
	_sortField = sortField;
}

template <class T>
void ArrayCountingSort<T>::Execute(IArrayCollection<T>& list)
{
	std::vector<T> output(list.GetSize());

	int max = _sortField(list[0]);
	for (auto i = 1; i < list.GetSize(); i++)
	{
		auto field = _sortField(list[i]);
		if (field > max)
			max = field;
	}

	//create count array (max+1 number of elements)
	std::vector<int> count(max + 1);

	//initialize count array to all zero
	for (auto i = 0; i < max + 1; i++)
		count[i] = 0;

	//increase number count in count array.
	for (auto i = 0; i < list.GetSize(); i++)
		++count[_sortField(list[i])];

	//find cumulative frequency
	for (auto i = 1; i < max + 1; i++)
		count[i] += count[i - 1];

	//decrease count for same numbers
	for (int i = list.GetSize() - 1; i >= 0; --i)
	{
		output[count[_sortField(list[i])] - 1] = list[i];
		count[_sortField(list[i])] -= 1;
	}

	//store output array to main array
	for (auto i = 0; i < list.GetSize(); i++)
	{
		list[i] = output[i];
	}
}