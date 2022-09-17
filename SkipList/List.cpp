#pragma once
#include "SkipNode.cpp"
#include "LinkedList.cpp"
#include "LinkedListNode.cpp"
#include <random>
#include <deque>


template<typename T>
class List
{
private:
	std::shared_ptr<LinkedList<SkipNode<T>>> head;
	int seed;
	int count;

	void deconstructionHelper(std::shared_ptr<IIndexable<SkipNode<T>>> parent, int index, std::shared_ptr<SkipNode<T>> targetNode)
	{
		if (!targetNode)
		{
			return;
		}
		deconstructionHelper(targetNode, index, (*targetNode)[index]);
		for (int i = targetNode->GetHeight() - 2; i >= 0; i--)
		{
			deconstructionHelper(targetNode, i, (*targetNode)[i]);
		}
		parent->SetAt(index, nullptr);
	}


public:

	List(int seed)
		:seed{ seed }
	{
		head = std::make_shared<LinkedList<SkipNode<T>>>();
		std::srand(seed);
	}

	~List()
	{
		for (int i = head->GetHeight() - 1; i >= 0; i--)
		{
			deconstructionHelper(head, i, (*head)[i]);
		}
		head = nullptr;
	}

	List(List<T>& copyList)
	{
		head = std::make_shared<LinkedList<SkipNode<T>>>(*(copyList.head));
		seed = copyList->seed;
		count = copyList->count;

		//traverse from the lowest level, copying the nodes as I add them to the List. Then, traverse from the higher levels and add the connections
	}


	void Add(T Value)
	{
		int increaseHeight = 1;
		int nodeHeight = 0;

		while (increaseHeight == 1)
		{
			nodeHeight += 1;
			increaseHeight = std::rand() % 2;
		}

		if (nodeHeight > head->GetHeight())
		{
			head->IncreaseHeight();
			nodeHeight = head->GetHeight();
		}

		std::shared_ptr<SkipNode<T>> newNode = std::make_shared<SkipNode<T>>(nodeHeight, Value);
		std::shared_ptr<IIndexable<SkipNode<T>>> parent = head;
		std::shared_ptr<SkipNode<T>> current;
		for (int i = head->GetHeight() - 1; i >= 0; i--)
		{
			current = (*parent)[i];
			while (current && current->Value < Value)
			{
				parent = current;
				current = (*current)[i];
			}
			if (newNode->GetHeight() > i)
			{
				newNode->SetAt(i, (*parent)[i]);
				parent->SetAt(i, newNode);
			}
		}

		count++;
	}

	bool Remove(T targetValue)
	{
		std::shared_ptr<IIndexable<SkipNode<T>>> parent = head;
		std::shared_ptr<SkipNode<T>> current;
		bool didRemove = false;
		for (int i = head->GetHeight() - 1; i >= 0; i--)
		{
			current = (*parent)[i];
			while (current && current->Value < targetValue)
			{
				parent = current;
				current = (*current)[i];
			}
			if (current && current->Value == targetValue)
			{
				parent->SetAt(i, (*current)[i]);
				didRemove = true;
			}
		}

		if (didRemove)
		{
			count--;
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetHeight()
	{
		return head->GetHeight();
	}

	int GetCount()
	{
		return count;
	}
};