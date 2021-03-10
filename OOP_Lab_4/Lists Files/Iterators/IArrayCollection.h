#pragma once

#include "IEnumerable.h"

#include <memory>

using std::shared_ptr;

/**
 * \brief Provides methods to work with array collection. 
 * Represents interface that provides methods to work with array collection.
 * \tparam T Type of data, that is in the collection.
 */
template <class T>
class IArrayCollection : public IEnumerable<T>, public std::enable_shared_from_this<IArrayCollection<T>>
{
public:
	/**
	 * Gives size of the collection.
	 * \return Size of the collection.
	 */
	virtual size_t GetSize() const = 0;
	
	/**
	 * Gives access to elements of the array collection.
	 * \param index Index of element to be returned.
	 * \return Element of the array collection.
	 */
	virtual T& operator [](size_t index) = 0;
};