#pragma once
#include <functional>

#include "INodeSort.h"
#include "../../Iterators/IArrayCollection.h"

template <class T>
class NodeBubbleSort final : public INodeSort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;

public:
	explicit NodeBubbleSort(std::function<bool(T, T)> comparePredicate);

	void Execute(INodeCollection<T>& list); //override;
};

template <class T>
NodeBubbleSort<T>::NodeBubbleSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void NodeBubbleSort<T>::Execute(INodeCollection<T>& list)
{
	/* Checking for empty list */
	if (list.GetSize() <= 1)
		return;

	bool isSwapped;
	Node<T>* last = nullptr;
	do
	{
		isSwapped = false;
		Node<T>* cur = list.GetHead();

		while (cur->GetNext() != last)
		{
			if (_comparePredicate(cur->GetData(), cur->GetNext()->GetData()))
			{
				auto temp = cur->GetData();
				cur->SetData(cur->GetNext()->GetData());
				cur->GetNext()->SetData(temp);
				isSwapped = true;
			}
			cur = cur->GetNext();
		}
		last = cur;
	}
	while (isSwapped);
}
