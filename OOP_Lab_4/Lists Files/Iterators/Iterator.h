#pragma once

using std::shared_ptr;

template <class T>
class Iterator
{
protected:
	virtual ~Iterator() = default;
	
public:
	virtual T CurrentItem() = 0;
	virtual T First() = 0;
	virtual bool MoveNext() = 0;
	virtual bool IsDone() = 0;
};