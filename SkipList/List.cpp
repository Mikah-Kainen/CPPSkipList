#pragma once
#include "SkipNode.cpp"
#include "LinkedList.cpp"
#include <random>


template<typename T>
class List
{
private:
	std::shared_ptr<LinkedList<SkipNode<T>>> head;
	int seed;
	int height;
	int count;

public:


	List(int seed)
		:seed{ seed }, height{ 1 }
	{
		head = std::make_shared<LinkedList<SkipNode<T>>>();
		std::srand(seed);
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
		std::shared_ptr<SkipNode<T>> current = (*head)[head->GetHeight() - 1];
		for (int i = head->GetHeight() - 1; i >= 0; i--)
		{
			current = (*parent)[i];
			while (current && current->Value < Value)
			{//if you move forwards while the current value is greater than your inserting value, you will stop when you find a smaller value, or only when you reach null, 
			 //meaning bigger values stop at the beginning, and smaller values stop at the end
				parent = current;
				current = (*current)[i];
			}
			//(*parent)[i] = newNode;
			//(*newNode)[i] = temp;
			if (newNode->GetHeight() > i)
			{
				newNode->SetAt(i, (*parent)[i]);
				parent->SetAt(i, newNode);
			}
		}

		if (newNode->GetHeight() > head->GetHeight())
		{
			head->IncreaseHeight();
			//(*head)[head->GetHeight() - 1] = newNode;
			//if ((*head)[head->GetHeight() - 1] != newNode)
			//{
			//	throw new std::exception("Whats Going on Here!");
			//	//whats going on here!
			//}
			head->SetAt(head->GetHeight() - 1, newNode);
			height++;
		}

		count++;
	}

	bool Remove()
	{

	}

	int GetHeight()
	{
		return height;
	}

	int GetCount()
	{
		return count;
	}
};