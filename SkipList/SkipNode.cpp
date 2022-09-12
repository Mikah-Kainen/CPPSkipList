#pragma once
#include <memory>
#include <random>
#include <exception>


template<typename TSkipNode>
/*abstract*/class IIndexable
{
public:
	virtual int GetHeight() = 0;

	virtual std::shared_ptr<TSkipNode> operator [](int index) = 0;
	virtual void SetAt(int index, std::shared_ptr<TSkipNode> newValue) = 0;
	virtual void IncreaseHeight() = 0;
};


template<typename T>
class SkipNode : public IIndexable<SkipNode<T>>
{
private:
	int height;

public:
	std::vector<std::shared_ptr<SkipNode<T>>> nodeConnections;
	T Value;

	int GetHeight()
	{
		return height;
	}

	SkipNode(int nodeHeight, T value)
		:Value{ value }
	{
		height = nodeHeight;

		for (int i = 0; i < nodeHeight; i++)
		{
			nodeConnections.push_back(nullptr);
		}
	}

	std::shared_ptr<SkipNode<T>> operator [](int index)
	{
		return nodeConnections[index];
	}

	void SetAt(int index, std::shared_ptr<SkipNode<T>> newValue)
	{
		nodeConnections[index] = newValue;
	}

	void IncreaseHeight()
	{
		throw std::exception("You can't increase the height of an array");
	}
};