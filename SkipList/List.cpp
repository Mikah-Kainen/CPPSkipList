#include "SkipNode.cpp"
#include "LinkedList.cpp"


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
	}

	void Add(T Value)
	{
		std::shared_ptr<SkipNode<T>> newNode = std::make_shared<SkipNode<T>>(seed, Value);
		for (int i = head->GetHeight() - 1; i < -1; i--)
		{
			std::shared_ptr<IIndexable<SkipNode<T>>> parent = head;
			std::shared_ptr<SkipNode<T>> current = (*head)[i];
			while (current && current->Value > Value)
			{
				parent = current;
				current = (*current)[i];
			}
			std::shared_ptr<SkipNode<T>> temp = (*parent)[i];
			(*parent)[i] = newNode;
			(*newNode)[i] = temp;
		}

		if (newNode->GetHeight() > head->GetHeight())
		{
			head->IncreaseHeight();
			(*head)[head->GetHeight() - 1] = newNode;
			if ((*head)[head->GetHeight() - 1] != newNode)
			{
				throw new std::exception("Whats Going on Here!");
				//whats going on here!
			}
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