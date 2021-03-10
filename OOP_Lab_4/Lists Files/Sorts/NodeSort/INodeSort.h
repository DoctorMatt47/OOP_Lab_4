#pragma once
#include "../../Iterators/INodeCollection.h"

/**
 * \brief Interface for node sort classes.
 * Represents method to sort the node collection.
 * \tparam T Type of data, that is in the collection.
 */
template <class T>
class INodeSort
{
protected:
	/**
	 * Default destructor.
	 */
	virtual ~INodeSort() = default;

public:
	/**
	 * Executes sorting algorithm. Sorts passed node collection
	 * \param list Node collection to be sorted.
	 */
	virtual void Execute(INodeCollection<T>& list) = 0;
};
