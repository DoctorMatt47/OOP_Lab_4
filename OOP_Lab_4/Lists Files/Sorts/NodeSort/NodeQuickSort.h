#pragma once
#include <functional>

#include "INodeSort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents quick sort of the node collection.
 * \tparam T Type of data, that is in the node collection.
 */
template <class T>
class NodeQuickSort final : public INodeSort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

	/**
	 * Additional function for Quick sort algorithm.
	 * \param l Low limit of the partition.
	 * \param h High limit of the partition.
	 * \return Pointer to middle node.
	 */
	Node<T>* Partition(Node<T>* l, Node<T>* h);

	/**
	 * Quick sort recursive algorithm.
	 * \param l Left node.
	 * \param h Right node.
	 */
	void QuickSortCore(Node<T>* l, Node<T>* h);

public:
	/**
	* Constructs quick sort object.
	* \param comparePredicate Predicate used to compare elements at the array.
	*/
	explicit NodeQuickSort(std::function<bool(T, T)> comparePredicate);

	void Execute(INodeCollection<T>& list) override;
};

template <class T>
Node<T>* NodeQuickSort<T>::Partition(Node<T>* l, Node<T>* h)
{
	// set pivot as h element  
	auto x = h->GetData();

	// similar to i = l-1 for array implementation  
	Node<T>* i = l->GetPrev();

	// Similar to "for (int j = l; j <= h- 1; j++)"  
	for (Node<T>* j = l; j != h; j = j->GetNext())
	{
		if (_comparePredicate(x, j->GetData()))
		{
			// Similar to i++ for array  
			i = (i == nullptr) ? l : i->GetNext();

			if (i != j)
			{
				T temp = i->GetData();
				i->SetData(j->GetData());
				j->SetData(temp);
			}
		}
	}
	i = (i == nullptr) ? l : i->GetNext(); // Similar to i++  
	if (i != h)
	{
		T temp = i->GetData();
		i->SetData(h->GetData());
		h->SetData(temp);
	}
	return i;
}

template <class T>
void NodeQuickSort<T>::QuickSortCore(Node<T>* l, Node<T>* h)
{
	if (h != nullptr && l != h && l != h->GetNext())
	{
		Node<T>* p = Partition(l, h);
		QuickSortCore(l, p->GetPrev());
		QuickSortCore(p->GetNext(), h);
	}
}

template <class T>
NodeQuickSort<T>::NodeQuickSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void NodeQuickSort<T>::Execute(INodeCollection<T>& list)
{
	auto tail = list.GetHead();
	while (tail->GetNext())
	{
		tail = tail->GetNext();
	}
	if (list.GetSize() > 1)
		QuickSortCore(list.GetHead(), tail);
}