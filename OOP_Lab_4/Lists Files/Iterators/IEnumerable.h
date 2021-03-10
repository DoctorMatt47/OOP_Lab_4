#pragma once

#include "Iterator.h"

#include <memory>

using std::shared_ptr;

/**
 * \brief Represent of iterable collection
 * Exposes an enumerator, which supports a simple iteration over a generic collection.
 * \tparam T Type of data, that is in the collection.
 */
template <class T>
class IEnumerable
{
protected:
	/**
	 * default virtual destructor
	 */
	virtual ~IEnumerable() = default;
	
public:
	/**
	 * Creates and returns an Iterator that can be used to iterate over the collection
	 * \return pointer to Iterator
	 */
	virtual shared_ptr<Iterator<T>> CreateIterator() = 0;
};