
#include <random>

template<typename T>
class SkipNode
{
private:

public:
	SkipNode* nodeConnections;

	SkipNode(int randSeed)
	{
		std::srand(randSeed);
		int increaseHeight = 1;
		int height = 0;
		while (increaseHeight == 1)
		{
			height += 1;
			increaseHeight = std::rand() % 2;
		}

		nodeConnections = new SkipNode(height);
	}

};