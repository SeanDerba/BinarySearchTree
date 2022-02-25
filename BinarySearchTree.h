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
	bool searchItem(ItemType a, TreeNode* node) const;
	void insertItem(ItemType a, TreeNode* &node);
	void deleteItem(ItemType a, TreeNode*& node);

	void printPreOrder(TreeNode* node) const;
	void printInOrder(TreeNode* node) const;
	void printPostOrder(TreeNode* node) const;

public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& a);

	bool isEmpty() const;
	bool isFull() const;

	int getSize() const;
	ItemType getRoot() const;	//pre: tree not empty, Post: root data is returned

	bool searchNode(ItemType a) const;
	void insertNode(ItemType a);	//pre: Value is not in tree | post: inserts node into tree
	void deleteNode(ItemType a);	//pre: Value is in tree, tree is not empty | post: removes 1 value from tree

	void printBSTpreOrder() const;
	void printBSTinOrder() const;
	void printBSTpostOrder() const;

	void operator= (const BinarySearchTree& a);
};

