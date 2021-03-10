#pragma once
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents bubble sort of the array collection.
 * \tparam T Type of data, that is in the array collection.
 */
template <class T>
class ArrayBubbleSort final : public IArraySort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

public:
	/**
	 * Constructs bubble sort object.
	 * \param comparePredicate Predicate used to compare elements at the array.
	 */
	explicit ArrayBubbleSort(std::function<bool(T, T)> comparePredicate);

	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
ArrayBubbleSort<T>::ArrayBubbleSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void ArrayBubbleSort<T>::Execute(IArrayCollection<T>& list)
{
	for (auto i = 0; i < list.GetSize() - 1; i++)
		for (auto j = 0; j < list.GetSize() - i - 1; j++)
			if (_comparePredicate(list[j], list[j + 1]))
				std::swap(list[j], list[j + 1]);
}
