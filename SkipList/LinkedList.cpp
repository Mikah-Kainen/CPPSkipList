#include "IIndexable.cpp"
#include "LinkedListNode.cpp"
#include <memory>

template<typename T>
class LinkedList : IIndexable<T>
{
private:
	std::shared_ptr<LinkedListNode<T>> tail; //tail is head

public:
	int Count; //make sure count is acurate!!!!

	T operator [](int targetIndex)
	{
		if (targetIndex > Count - 1)
		{
			std::shared_ptr<LinkedListNode<T>> oldTail = tail;
			tail = std::make_shared(LinkedListNode<T>());
			tail->DownLink = oldTail;
		}
		std::shared_ptr<LinkedListNode<T>> current = tail;
		for(int currentIndex = Count -1; currentIndex > -1; currentIndex --)
		{
			current = current->NextLink;
		}

		return current;
	}
	//change this to a standard increase height then attach then search and attach the rest
};
