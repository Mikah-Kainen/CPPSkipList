#include "IIndexable.cpp"
#include "LinkedListNode.cpp"

template<typename T>
class LinkedList : IIndexable<T>
{
private:
	LinkedListNode<T> head;
	LinkedListNode<T> tail;

public:
	int Count;

	overload T[](int index)
	{
		
	}
};
