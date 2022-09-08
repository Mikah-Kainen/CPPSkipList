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

	SkipNode(int randSeed, T value)
		:Value{value}
	{
		std::srand(randSeed);
		int increaseHeight = 1;
		height = 0;	
		
		while (increaseHeight == 1)
		{
			height += 1;
			increaseHeight = std::rand() % 2;
		}
	}

	std::shared_ptr<SkipNode<T>> operator [](int index)
	{
		return nodeConnections[index];
	}

	void IncreaseHeight()
	{
		throw std::exception("You can't increase the height of an array");
	}
};