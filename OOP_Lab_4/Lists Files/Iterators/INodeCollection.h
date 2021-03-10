#pragma once

#include "IEnumerable.h"

#include <memory>

#include "../Node.h"

using std::shared_ptr;

/**
 * \brief Provides methods to work with node collection.
 * Represents interface that provides methods to work with node collection.
 * \tparam T Type of data, that is in node the collection.
 */
template <class T>
class INodeCollection : public IEnumerable<T>, public std::enable_shared_from_this<INodeCollection<T>>
{
public:
	/**
	 * Returns first Node of the node collection.
	 * \return First Node.
	 */
	virtual Node<T>* GetHead() const = 0;
	
	/**
	 * Gives size of the node collection.
	 * \return Size of the node collection.
	 */
	virtual size_t GetSize() const = 0;
};
