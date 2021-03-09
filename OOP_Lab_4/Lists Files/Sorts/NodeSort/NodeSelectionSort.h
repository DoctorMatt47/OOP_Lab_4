#pragma once
#include <functional>

#include "INodeSort.h"
#include "../../Iterators/IArrayCollection.h"

template <class T>
class NodeSelectionSort final : public INodeSort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

public:
	explicit NodeSelectionSort(std::function<bool(T, T)> comparePredicate);

	void Execute(INodeCollection<T>& list) override;
};

template <class T>
NodeSelectionSort<T>::NodeSelectionSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void NodeSelectionSort<T>::Execute(INodeCollection<T>& list)
{
	Node<T>* temp = list.GetHead();

	// Traverse the List 
	while (temp)
	{
		Node<T>* min = temp;
		Node<T>* r = temp->GetNext();

		// Traverse the unsorted sublist 
		while (r)
		{
			if (_comparePredicate(min->GetData(), r->GetData()))
				min = r;

			r = r->GetNext();
		}

		// Swap Data 
		auto x = temp->GetData();
		temp->SetData(min->GetData());
		min->SetData(x);
		temp = temp->GetNext();
	}
}