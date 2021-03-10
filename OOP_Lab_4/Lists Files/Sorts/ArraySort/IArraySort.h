#pragma once
#include "../../Iterators/IArrayCollection.h"

/**
 * \brief Interface for array sort classes.
 * Represents method to sort the array collection.
 * \tparam T Type of data, that is in the collection.
 */
template <class T>
class IArraySort
{
protected:
	/**
	 * Default destructor.
	 */
	virtual ~IArraySort() = default;
	
public:
	/**
	 * Executes sorting algorithm. Sorts passed array collection.
	 * \param list Array collection to be sorted.
	 */
	virtual void Execute(IArrayCollection<T>& list) = 0;
};
