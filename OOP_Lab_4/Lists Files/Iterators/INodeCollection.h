#pragma once

#include "IEnumerable.h"

#include <memory>

#include "../Node.h"

using std::shared_ptr;

template <class T>
class INodeCollection : public IEnumerable<T>, public std::enable_shared_from_this<INodeCollection<T>>
{
public:
	virtual Node<T>* GetHead() const = 0;
	
	virtual size_t GetSize() const = 0;
};
