#pragma once
#include <stdexcept>
#include <memory>


template<typename TSkipNode>
/*abstract*/class IIndexable
{
public:

	virtual std::shared_ptr<TSkipNode> operator [](int index) = 0;
	virtual void IncreaseHeight() = 0;
};
