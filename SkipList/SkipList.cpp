// SkipList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.cpp"
#include "SkipNode.cpp"
#include <vector>

enum Food
{
	Food1 = 1,
	Food2,
	Food3,
	Food4,
	Food5,
};


int main()
{

	

	const int vectorLength = 500;
	//SkipNode<int> nodeArray[vectorLength];
	////List<int> newList = 0;

	int seedCount = 200;

	while (true)
	{
		seedCount++;
		std::string input = "start\n";		
		std::cin >> input;

		std::cout << "vector alive\n";
		//std::vector<SkipNode<int>> skipNodeVector = std::vector<SkipNode<int>>();
		//std::vector < LinkedListNode<SkipNode<int>>> linkedNodeVector = std::vector<LinkedListNode<SkipNode<int>>>();
		List<int> list(seedCount);

		std::cin >> input;


		for (int i = 0; i < vectorLength; i++)
		{
			//skipNodeVector.push_back(SkipNode<int>(1, i));
			//linkedNodeVector.push_back(LinkedListNode<SkipNode<int>>());
			list.Add(i);
		}

		std::cout << "Added " << vectorLength << " Nodes\n";

		std::cin >> input;

		for (int i = 0; i < vectorLength; i += 1)
		{
			list.Remove(i);
		}
		//linkedNodeVector.clear();
		//skipNodeVector.clear();
		std::cout << "Removed " << vectorLength << " Nodes\n";
		//list.Remove(20);
		//list.Remove(3);
		//list.Remove(7);

		//	//newList = list;
	}


	while (true)
	{

	}
	//check if the LinkedList and the SkipNode indexers work
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
