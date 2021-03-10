#pragma once
#include <algorithm>
#include <functional>

#include "IArraySort.h"
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Represents bucket sort of the array collection.
 * \tparam T Type of data, that is in the array collection.
 */
template <class T>
class ArrayBucketSort final : public IArraySort<T>
{
private:
	std::function<float(T)> _sortField;

public:
	/**
	* Constructs bucket sort object.
	* \param sortField Function returns field which used to compare elements at the list.
	* This field must be float and from zero to one.
	*/
	explicit ArrayBucketSort(std::function<float(T)> sortField);

	void Execute(IArrayCollection<T>& list) override;
};

template <class T>
ArrayBucketSort<T>::ArrayBucketSort(std::function<float(T)> sortField)
{
	_sortField = sortField;
}

template <class T>
void ArrayBucketSort<T>::Execute(IArrayCollection<T>& list)
{
	// 1) Create n empty buckets 
	std::vector<std::vector<T>> b(list.GetSize());

	// 2) Put array elements in different buckets 
	for (auto i = 0; i < list.GetSize(); i++)
	{
		const auto bi = static_cast<int>(list.GetSize() * _sortField(list[i])); // Index in bucket 
		b[bi].push_back(list[i]);
	}

	// 3) Sort individual buckets 
	for (auto i = 0; i < list.GetSize(); i++)
		std::sort(b[i].begin(), b[i].end(), [this](T t1, T t2)
		{
			return _sortField(t1) < _sortField(t2);
		});

	// 4) Concatenate all buckets into arr[] 
	auto index = 0;
	for (auto i = 0; i < list.GetSize(); i++)
		for (auto j = 0; j < b[i].size(); j++)
			list[index++] = b[i][j];
}
