#pragma once
#include "../../Iterators/INodeCollection.h"

template <class T>
class INodeSort
{
protected:
	virtual ~INodeSort() = default;

public:
	virtual void Execute(INodeCollection<T>& list) = 0;
};
