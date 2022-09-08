#pragma once
#include <memory>
#include <random>
#include <exception>


template<typename TSkipNode>
/*abstract*/class IIndexable
{
public:
	int Test;
	virtual int GetHeight() = 0;

	virtual std::shared_ptr<TSkipNode> operator [](int index) = 0;
	virtual void IncreaseHeight() = 0;
};


template<typename T>
class SkipNode : public IIndexable<SkipNode<T>>, IIndexable<SkipNode<long>>
{
private:

public:
	std::vector<std::shared_ptr<SkipNode<T>>> nodeConnections;
	int Height;
	T Value;

	int GetHeight() 
	{ 
		return Height + IIndexable<SkipNode<T>>::Test + IIndexable<SkipNode<long>>::Test;
	}

	SkipNode(int randSeed)
	{
		std::srand(randSeed);
		int increaseHeight = 1;
		Height = 0;	
		
		while (increaseHeight == 1)
		{
			Height += 1;
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