#pragma once

#include "IEnumerable.h"

#include <memory>

using std::shared_ptr;

template <class T>
class IArrayCollection : public IEnumerable<T>, public std::enable_shared_from_this<IArrayCollection<T>>
{
public:
	virtual size_t GetSize() const = 0;
	
	virtual T& operator [](size_t index) = 0;
};