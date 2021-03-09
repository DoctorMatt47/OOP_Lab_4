#pragma once
#include "../../Iterators/IArrayCollection.h"

template <class T>
class IArraySort
{
protected:
	virtual ~IArraySort() = default;
	
public:
	virtual void Execute(IArrayCollection<T>& list) = 0;
};
