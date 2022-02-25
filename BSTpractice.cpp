// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree tree = BinarySearchTree();
	tree.insertNode(10);
	tree.insertNode(7);
	tree.insertNode(20);
	tree.insertNode(15);
	tree.insertNode(1);
	tree.insertNode(12);
	tree.printBSTinOrder();
}

