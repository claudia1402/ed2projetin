// mainBST.cpp
#include <iostream>
#include <string>
#include "BST.h"
#include "BST.cpp"


void PrintNode(NodeBST* node)
{
	if (node == nullptr) return;
	std::cout << "N:" << node->GetID()
		<< "(" << node->GetData() << ")"
		<< " Parent:" << (node->GetParent() != nullptr ? node->GetParent()->GetID() : -1)
		<< " Left:" << (node->GetLeft() != nullptr ? node->GetLeft()->GetID() : -1)
		<< " Right:" << (node->GetRight() != nullptr ? node->GetRight()->GetID() : -1)
		<< " Degree: " << node->GetDegree()
		<< " Depth: " << node->GetDepth()
		<< " Height: " << node->GetHeight() << '\n';
}

void Insert(BST* bst)
{
	int num;
	std::cout << "Insert number: ";
	std::cin >> num;
	NodeBST* node = bst->Insert(num, std::to_string(num));
	if (node)
	{
		std::cout << "Node inserted:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(BST* bst)
{
	int num;
	std::cout << "Remove number: ";
	std::cin >> num;
	bst->Remove(num);
}

void Search(BST* bst)
{
	int num;
	std::cout << "Search number: ";
	std::cin >> num;
	NodeBST* node = bst->Search(num);
	if (node)
	{
		std::cout << "Node found:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(BST* bst)
{
	int num;
	std::cout << "Find predecessor of: ";
	std::cin >> num;
	NodeBST* node = bst->Predecessor(num);
	if (node)
	{
		std::cout << "Predecessor of " << num << ":\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! There is no predecessor of " << num << "!\n";
}

void Successor(BST* bst)
{
	int num;
	std::cout << "Find successor of: ";
	std::cin >> num;
	NodeBST* node = bst->Successor(num);
	if (node)
	{
		std::cout << "Successor of " << num << ":\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! There is no successor of " << num << "!\n";
}

void FindMin(BST* bst)
{
	NodeBST* node = bst->FindMin();
	if (node)
	{
		std::cout << "Minimum:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(BST* bst)
{
	NodeBST* node = bst->FindMax();
	if (node)
	{
		std::cout << "Maximum:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(BST* bst)
{
	std::cout << bst->TraverseInOrder() << '\n';
}

void TraversePreOrder(BST* bst)
{
	std::cout << bst->TraversePreOrder() << '\n';
}

void TraversePostOrder(BST* bst)
{
	std::cout << bst->TraversePostOrder() << '\n';
}

void TraverseBST(NodeBST* node)
{
	if (node != nullptr)
	{
		TraverseBST(node->GetLeft());
		PrintNode(node);
		TraverseBST(node->GetRight());
	}
}

int main()
{
	 
	BST* bst = new BST();

	int values[] = { 30, 15, 38, 10, 20, 51, 8, 16, 27 };
	for (int value : values)
		bst->Insert(value, std::to_string(value));

	
	int option = 0;
	do
	{
		std::cout << "*** BST Tree ***\n"
			<< "[1] Insert\n"
			<< "[2] Remove\n"
			<< "[3] Search\n"
			<< "[4] Predecessor\n"
			<< "[5] Successor\n"
			<< "[6] Find minimum\n"
			<< "[7] Find maximum\n"
			<< "[8] Traverse in-order\n"
			<< "[9] Traverse pre-order\n"
			<< "[10] Traverse post-order\n"
			<< "[11] In-order with all node data\n"
			<< "[12] Clear\n"
			<< "[0] Exit\nOption: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1: Insert(bst); break;
		case 2: Remove(bst); break;
		case 3: Search(bst); break;
		case 4: Predecessor(bst); break;
		case 5: Successor(bst); break;
		case 6: FindMin(bst); break;
		case 7: FindMax(bst); break;
		case 8: TraverseInOrder(bst); break;
		case 9: TraversePreOrder(bst); break;
		case 10: TraversePostOrder(bst); break;
		case 11: TraverseBST(bst->GetRoot()); break;
		case 12: bst->Clear(); break;
		}

		std::cout << '\n';
	} while (option != 0);

	delete bst;
	return 0;
}

