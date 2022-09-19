#pragma once
#include "LinkedListNode.cpp"
#include <memory>
#include <exception>

template<typename TSkipNode>
class LinkedList :public IIndexable<TSkipNode>
{
private:
	int height;
	std::shared_ptr<LinkedListNode<TSkipNode>> tail; //tail is head

	void deconstructionHelper(std::shared_ptr<LinkedListNode<TSkipNode>> targetNode)
	{
		if (!targetNode)
		{
			return;
		}

		deconstructionHelper(targetNode->DownLink);
		//targetNode->SkipNodeLink = nullptr;
		targetNode->DownLink = nullptr;
	}

public:

	LinkedList()
		:height{ 1 }
	{
		tail = std::make_shared<LinkedListNode<TSkipNode>>();
	}

	~LinkedList()
	{
		deconstructionHelper(tail);
		tail = nullptr;
	}

	LinkedList(LinkedList<TSkipNode>& copyList)
	{
		tail = std::make_shared<LinkedListNode<TSkipNode>>();
		std::shared_ptr<LinkedListNode<TSkipNode>> parent = tail;
		std::shared_ptr<LinkedListNode<TSkipNode>> copyCurrent = copyList.tail->DownLink;
		while (copyCurrent)
		{
			parent->DownLink = std::make_shared<LinkedListNode<TSkipNode>>();
			parent = parent->DownLink;
			copyCurrent = copyCurrent->DownLink;
		}
		height = copyList.GetHeight();
	}

	int GetHeight()
	{
		return height;
	}

	std::shared_ptr<TSkipNode> operator [](int targetIndex)
	{
		if (targetIndex > height - 1)
		{
			throw std::bad_exception();
		}
		std::shared_ptr<LinkedListNode<TSkipNode>> current = tail;
		for(int currentIndex = height -1; currentIndex != targetIndex; currentIndex --)
		{
			current = current->DownLink;
		}

		return current->SkipNodeLink;
	}

	void SetAt(int index, std::shared_ptr<TSkipNode> newValue)
	{
		if (index > height - 1)
		{
			throw std::bad_exception();
		}
		std::shared_ptr<LinkedListNode<TSkipNode>> current = tail;
		for (int currentIndex = height - 1; currentIndex != index; currentIndex--)
		{
			current = current->DownLink;
		}

		current->SkipNodeLink = newValue;
	}


	//this is a standard increase height then attach then search and attach the rest
	void IncreaseHeight()
	{
		std::shared_ptr<LinkedListNode<TSkipNode>> oldTail = tail;
		tail = std::make_shared<LinkedListNode<TSkipNode>>();
		tail->DownLink = oldTail;
		height++;
	}
};
