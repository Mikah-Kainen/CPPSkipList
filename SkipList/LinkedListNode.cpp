#include <memory>
#include "SkipNode.cpp"


template<typename T>
class LinkedListNode
{
private:


public:
	std::shared_ptr<SkipNode<T>> SkipNodeLink;
	std::shared_ptr<LinkedListNode<T>> DownLink;

	LinkedListNode()
	{

	}
};