#include <memory>
#include "SkipNode.cpp"


template<typename TSkipNode>
class LinkedListNode
{
private:


public:
	std::shared_ptr<TSkipNode> SkipNodeLink;
	std::shared_ptr<LinkedListNode<TSkipNode>> DownLink;
};