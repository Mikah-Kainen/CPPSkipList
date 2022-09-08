#include "SkipNode.cpp"
#include "LinkedList.cpp"


template<typename T>
class List
{
private:
	LinkedList<SkipNode<T>> head;


public:
	int Count;
	int Height;

};