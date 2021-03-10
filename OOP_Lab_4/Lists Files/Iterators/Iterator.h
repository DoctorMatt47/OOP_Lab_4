#pragma once

using std::shared_ptr;

/**
 * \brief Represents access to elements of the collection.
 * Represents interface that provides access to elements of the collection and methods to iterate it.
 * \tparam T Type of data, that is in the collection.
 */
template <class T>
class Iterator
{
protected:
	/**
	 * Default virtual destructor.
	 */
	virtual ~Iterator() = default;
	
public:
	/**
	 * Returns item that is pointed to by iterator.
	 * \return Current item in the collection
	 */
	virtual T CurrentItem() = 0;
	
	/**
	 * Returns first item in the collection.
	 * \return first item in the collection.
	 */
	virtual T First() = 0;
	
	/**
	 * Moves iterator to the next position, if it possible.
	 * \return True, if moving has been done successfully, else false.
	 */
	virtual bool MoveNext() = 0;
	/**
	 * Returns true, if iterator is pointed to the last element of the collection. 
	 * \return True, if iteration is over.
	 */
	virtual bool IsDone() = 0;
};