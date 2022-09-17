#pragma once
#include <memory>
#include "SkipNode.cpp"
#include <exception>


template<typename TSkipNode>
class LinkedListNode
{
private:


public:
	std::shared_ptr<TSkipNode> SkipNodeLink;
	std::shared_ptr<LinkedListNode<TSkipNode>> DownLink;

	~LinkedListNode()
	{
		if (SkipNodeLink)
		{
			throw new std::exception("This shouldn't happen exception");
			SkipNodeLink = nullptr;
		}
		if (DownLink)
		{
			throw new std::exception("This shouldn't happen either exception");
			DownLink = nullptr;
		}
	}
};