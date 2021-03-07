#pragma once
#include "IEnumerable.h"
#include "INodeCollection.h"
#include "Iterator.h"
#include "../Node.h"

using std::make_shared;

template <class T>
class ArrayIterator final : public Iterator<T>
{
private:
	shared_ptr<IArrayCollection<T>> _enumerable;
	size_t _size;
	int _current = 0;

public:
	explicit ArrayIterator(shared_ptr<IArrayCollection<T>> enumerable);

	T First() override;

	bool MoveNext() override;

	T CurrentItem() override;

	bool IsDone() override;
};

template <class T>
ArrayIterator<T>::ArrayIterator(shared_ptr<IArrayCollection<T>> enumerable)
{
	_enumerable = enumerable;
	_size = enumerable->GetSize();
}

template <class T>
T ArrayIterator<T>::First()
{
	return (*_enumerable)[0];
}

template <class T>
bool ArrayIterator<T>::MoveNext()
{
	if (_current + 1 >= _size) return false;
	_current++;
	return true;
}

template <class T>
T ArrayIterator<T>::CurrentItem()
{
	return (*_enumerable)[_current];
}

template <class T>
bool ArrayIterator<T>::IsDone()
{
	if (_current + 1 >= _size) return true;
	return false;
}
