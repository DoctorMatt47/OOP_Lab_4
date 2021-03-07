#pragma once

#include "Iterator.h"

#include <memory>

using std::shared_ptr;

template <class T>
class IEnumerable
{
protected:
	virtual ~IEnumerable() = default;
	
public:
	virtual shared_ptr<Iterator<T>> CreateIterator() = 0;
};