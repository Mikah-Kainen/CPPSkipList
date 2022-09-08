#include "LinkedListNode.cpp"
#include <memory>
#include <exception>

template<typename TSkipNode>
class LinkedList :public IIndexable<TSkipNode>
{
private:
	std::shared_ptr<LinkedListNode<TSkipNode>> tail; //tail is head

public:
	int Height; //make sure count is acurate!!!!

	LinkedList()
		:Height{ 1 }
	{
		tail = std::make_shared<LinkedListNode<TSkipNode>>();
	}

	int GetHeight()
	{
		return Height;
	}

	std::shared_ptr<TSkipNode> operator [](int targetIndex)
	{
		if (targetIndex > Height - 1)
		{
			//throw std::bad_exception("Index Out of Range");
		}
		std::shared_ptr<LinkedListNode<TSkipNode>> current = tail;
		for(int currentIndex = Height -1; currentIndex != targetIndex; currentIndex --)
		{
			current = current->DownLink;
		}

		return current->SkipNodeLink;
	}

	//this is a standard increase height then attach then search and attach the rest
	void IncreaseHeight()
	{
		std::shared_ptr<LinkedListNode<TSkipNode>> oldTail = tail;
		tail = std::make_shared<LinkedListNode<TSkipNode>>();
		tail->DownLink = oldTail;
		Height++;
	}
};
