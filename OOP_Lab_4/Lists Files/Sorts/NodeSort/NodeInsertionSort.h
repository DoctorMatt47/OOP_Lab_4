#pragma once
#include <functional>

#include "INodeSort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents insertion sort of the node collection.
 * \tparam T Type of data, that is in the node collection.
 */
template <class T>
class NodeInsertionSort final : public INodeSort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

public:
	/**
	* Constructs insertion sort object.
	* \param comparePredicate Predicate used to compare elements at the array.
	*/
	explicit NodeInsertionSort(std::function<bool(T, T)> comparePredicate);

	void Execute(INodeCollection<T>& list) override;
};

template <class T>
NodeInsertionSort<T>::NodeInsertionSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void NodeInsertionSort<T>::Execute(INodeCollection<T>& list)
{
	if (list.GetSize() <= 1) return;

	for (Node<T>* i = list.GetHead()->GetNext(); i != nullptr; i = i->GetNext())
	{
		T key = i->GetData();
		Node<T>* j = i->GetPrev();

		while (j && _comparePredicate(j->GetData(), key))
		{
			j->GetNext()->SetData(j->GetData());
			j = j->GetPrev();
		}

		if (j)
			j->GetNext()->SetData(key);
		else
			list.GetHead()->SetData(key);
	}
}