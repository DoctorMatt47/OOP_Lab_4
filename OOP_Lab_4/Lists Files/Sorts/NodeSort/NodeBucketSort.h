#pragma once
#include <algorithm>
#include <functional>

#include "INodeSort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents bucket sort of the node collection.
 * \tparam T Type of data, that is in the node collection.
 */
template <class T>
class NodeBucketSort final : public INodeSort<T>
{
private:
	std::function<float(T)> _sortField;

public:
	/**
	* Constructs bucket sort object.
	* \param sortField Function returns field which used to compare elements at the list.
	* This field must be float and from zero to one.
	*/
	explicit NodeBucketSort(std::function<float(T)> sortField);

	void Execute(INodeCollection<T>& list) override;
};

template <class T>
NodeBucketSort<T>::NodeBucketSort(std::function<float(T)> sortField)
{
	_sortField = sortField;
}

template <class T>
void NodeBucketSort<T>::Execute(INodeCollection<T>& list)
{
	// 1) Create n empty buckets
	auto n = list.GetSize();
	std::vector<std::vector<T>> b(n);

	// 2) Put array elements in different buckets 
	for (Node<T>* index = list.GetHead(); index; index = index->GetNext())
	{
		auto bi = static_cast<int>(n * _sortField(index->GetData())); // Index in bucket
		b[bi].push_back(index->GetData());
	}

	// 3) Sort individual buckets 
	for (size_t i = 0; i < n; i++)
		std::sort(b[i].begin(), b[i].end(), [this](T t1, T t2)
		{
			return _sortField(t1) < _sortField(t2);
		});

	// 4) Concatenate all buckets into arr[] 
	Node<T>* index = list.GetHead();
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < b[i].size(); j++)
		{
			index->SetData(b[i][j]);
			index = index->GetNext();
		}
}