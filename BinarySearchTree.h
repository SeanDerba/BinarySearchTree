#pragma once


typedef int ItemType;
struct TreeNode {
	ItemType data;
	TreeNode* left;
	TreeNode* right;
};


class BinarySearchTree
{
private:
	int size;
	TreeNode* root;

	int getSize(TreeNode* node) const;
	bool searchNode(ItemType a, TreeNode* node) const;
	void insertNode(ItemType a, TreeNode* &node);

public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& a);
	bool isEmpty() const;
	bool isFull() const;
	int getSize() const;
	ItemType getRoot() const;	//pre: tree not empty, Post: root data is returned
	bool searchNode(ItemType a) const;
	void insertNode(ItemType a);
	void deleteNode(ItemType a);
	void printBSTpreOrder() const;
	void printBSTinOrder() const;
	void printBSTpostOrder() const;

	void operator= (const BinarySearchTree& a);
};

