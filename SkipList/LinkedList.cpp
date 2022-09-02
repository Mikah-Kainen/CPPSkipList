#include "IIndexable.cpp"
#include "LinkedListNode.cpp"
#include <memory>
#include <exception>

template<typename TSkipNode>
class LinkedList :public IIndexable<TSkipNode>
{
private:
	std::shared_ptr<LinkedListNode<TSkipNode>> tail; //tail is head

public:
	int Count; //make sure count is acurate!!!!

	LinkedList()
		:Count{ 1 }
	{
		tail = std::make_shared<LinkedListNode<TSkipNode>>();
	}

	std::shared_ptr<TSkipNode> operator [](int targetIndex)
	{
		if (targetIndex > Count - 1)
		{
			//throw std::bad_exception("Index Out of Range");
		}
		std::shared_ptr<LinkedListNode<TSkipNode>> current = tail;
		for(int currentIndex = Count -1; currentIndex != targetIndex; currentIndex --)
		{
			current = current->SkipNodeLink;
		}

		return current->SkipNodeLink;
	}
	//change this to a standard increase height then attach then search and attach the rest

	void IncreaseHeight()
	{
		std::shared_ptr<LinkedListNode<TSkipNode>> oldTail = tail;
		tail = std::make_shared<LinkedListNode<TSkipNode>>();
		tail->DownLink = oldTail;
		Count++;
	}
};
