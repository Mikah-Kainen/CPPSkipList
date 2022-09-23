#pragma once
#include "SkipNode.cpp"
#include "LinkedList.cpp"
#include "LinkedListNode.cpp"
#include <random>
#include <deque>


static int heightOne = 0;
static int totalNodes = 0;

template<typename T>
class List
{
private:
	std::shared_ptr<LinkedList<SkipNode<T>>> head;
	int seed;
	int count;

	void deconstructionHelper(std::shared_ptr<IIndexable<SkipNode<T>>> parent, int index)
	{
		std::shared_ptr<SkipNode<T>> targetNode = (*parent)[index];
		if (!targetNode)
		{
			return;
		}
		//deconstructionHelper(targetNode, index, (*targetNode)[index]);
		//for (int i = targetNode->GetHeight() - 1; i >= 0; i--)
		//{
		//	deconstructionHelper(targetNode, i, (*targetNode)[i]);
		//}
		deconstructionHelper(targetNode, index);
		parent->SetAt(index, nullptr);
		if (index >= 1)
		{
			deconstructionHelper(targetNode, index - 1);
		}
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
			deconstructionHelper(head, i);
		}
		head = nullptr;
	}

	List(List<T>& copyList)

	{
		//LinkedList<SkipNode<T>> copy(*copyList.head);
		head = std::make_shared<LinkedList<SkipNode<T>>>((*copyList.head));
		//head = std::make_shared<LinkedList<SkipNode<T>>>();
		//head->IncreaseHeight();
		seed = copyList.seed;
		count = copyList.count;

		std::vector<std::shared_ptr<IIndexable<SkipNode<T>>>> previousNodes = std::vector<std::shared_ptr<IIndexable<SkipNode<T>>>>();
		for (int i = 0; i < head->GetHeight(); i++)
		{
			previousNodes.push_back(head);
		}

		std::shared_ptr<SkipNode<T>> fakeCurrent = (*copyList.head)[0];
		while (fakeCurrent)
		{
			std::shared_ptr<SkipNode<T>> temp = std::make_shared<SkipNode<T>>(SkipNode<T>(fakeCurrent->GetHeight(), fakeCurrent->Value));
			for (int i = 0; i < fakeCurrent->GetHeight(); i++)
			{
				previousNodes[i]->SetAt(i, temp);
				previousNodes[i] = temp;
			}
			fakeCurrent = (*fakeCurrent)[0];
		}

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

		if (nodeHeight == 1)
		{
			heightOne++;
		}
		totalNodes++;

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
				/*parent->SetAt(i, nullptr);*/
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