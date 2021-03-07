#pragma once
#include "IEnumerable.h"
#include "INodeCollection.h"
#include "Iterator.h"
#include "../Node.h"

using std::make_shared;

template <class T>
class NodeIterator final : public Iterator<T>
{
private:
	shared_ptr<INodeCollection<T>> _enumerable;
	Node<T>* _current;
	
public:
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
