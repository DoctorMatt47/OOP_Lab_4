#pragma once
#include <functional>

#include "INodeSort.h"
#include "../../Iterators/IArrayCollection.h"

template <class T>
class NodeCountingSort final : public INodeSort<T>
{
private:
	std::function<size_t(T)> _sortField;

public:
	explicit NodeCountingSort(std::function<size_t(T)> sortField);

	void Execute(INodeCollection<T>& list) override;
};

template <class T>
NodeCountingSort<T>::NodeCountingSort(std::function<size_t(T)> sortField)
{
	_sortField = sortField;
}

template <class T>
void NodeCountingSort<T>::Execute(INodeCollection<T>& list)
{
	std::vector<size_t> buckets;
	for (Node<T>* i = list.GetHead(); i != nullptr; i = i->GetNext())
	{
		const int field = _sortField(i->GetData());

		//Increase the bucket size, if necessary
		for (int j = buckets.size(); j <= field; j++)
			buckets.push_back(0);

		++buckets[field];
	}
	const auto size = buckets.size();
	std::vector<size_t> startIndex(buckets.size());
	for (size_t j = 1; j < buckets.size(); j++)
	{
		startIndex[j] = buckets[j - 1] + startIndex[j - 1];
	}

	std::vector<T> result(list.GetSize());
	for (Node<T>* i = list.GetHead(); i != nullptr; i = i->GetNext())
	{
		const int field = _sortField(i->GetData());
		auto destIndex = startIndex[field]++;
		result[destIndex] = i->GetData();
	}

	auto node = list.GetHead();
	for (auto i = 0; i < result.size(); i++)
	{
		node->SetData(result[i]);
		node = node->GetNext();
	}
}