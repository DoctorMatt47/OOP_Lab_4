#pragma once
#include <functional>

#include "INodeSort.h"
#include "../../Iterators/IArrayCollection.h"

template <class T>
class NodeGnomeSort final : public INodeSort<T>
{
private:
	std::function<bool(T, T)> _comparePredicate;
	
public:
	explicit NodeGnomeSort(std::function<bool(T, T)> comparePredicate);
	
	void Execute(INodeCollection<T>& list) override;
};

template <class T>
NodeGnomeSort<T>::NodeGnomeSort(std::function<bool(T, T)> comparePredicate)
{
	_comparePredicate = comparePredicate;
}

template <class T>
void NodeGnomeSort<T>::Execute(INodeCollection<T>& list)
{
	Node<T>* index = list.GetHead();

	while (index)
	{
		if (index == list.GetHead())
			index = index->GetNext();

		if (_comparePredicate(index->GetData(), index->GetPrev()->GetData()))
			index = index->GetNext();

		else
		{
			auto temp = index->GetData();
			index->SetData(index->GetPrev()->GetData());
			index->GetPrev()->SetData(temp);
			index = index->GetPrev();
		}
	}
}
