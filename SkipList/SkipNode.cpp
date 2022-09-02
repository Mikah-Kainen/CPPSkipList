#pragma once
#include "IIndexable.cpp"
#include <memory>
#include <random>
#include <exception>

template<typename T>
class SkipNode : IIndexable<SkipNode<T>>
{
private:

public:
	std::vector<std::shared_ptr<SkipNode<T>>> nodeConnections;
	int Height;

	SkipNode(int randSeed)
	{
		std::srand(randSeed);
		int increaseHeight = 1;
		Height = 0;
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