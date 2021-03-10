#pragma once
#include "IEnumerable.h"
#include "INodeCollection.h"
#include "Iterator.h"
#include "../Node.h"

using std::make_shared;

/**
 * \brief Represents access to elements of the node collection.
 * Provides access to elements of the node collection and methods to iterate it.
 * \tparam T Type of data, that is in the collection.
 */
template <class T>
class NodeIterator final : public Iterator<T>
{
private:
	shared_ptr<INodeCollection<T>> _enumerable;
	Node<T>* _current;
	
public:
	/**
	 * Constructs a node iterator.
	 * \param enumerable Node collection.
	 */
	explicit NodeIterator(shared_ptr<INodeCollection<T>> enumerable);

	T First() override;

	bool MoveNext() override;

	T CurrentItem() override;

	bool IsDone() override;
};

template <class T>
NodeIterator<T>::NodeIterator(shared_ptr<INodeCollection<T>> enumerable)
{
	_enumerable = enumerable;
	_current = _enumerable->GetHead();
}

template <class T>
T NodeIterator<T>::First()
{
	return _enumerable->GetHead()->GetData();
}

template <class T>
bool NodeIterator<T>::MoveNext()
{
	_current = _current->GetNext();
	return _current;
}

template <class T>
T NodeIterator<T>::CurrentItem()
{
	return _current->GetData();
}

template <class T>
bool NodeIterator<T>::IsDone()
{
	return !_current;
}
