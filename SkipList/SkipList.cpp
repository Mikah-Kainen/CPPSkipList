// SkipList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.cpp"

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
	std::string input = "bla";
	std::cin >> input;
	List<int> newList = 0;
	{
		List<int> list(102);
		list.Add(5);
		list.Add(12);
		list.Add(7);
		list.Add(3);
		list.Add(20);
		for (int i = 100; i < 1000; i++)
		{
			list.Add(i);
		}

		list.Remove(20);
		list.Remove(3);
		list.Remove(7);

		std::cout << "Hello World!\n";

		std::cin >> input;
		newList = list;
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
