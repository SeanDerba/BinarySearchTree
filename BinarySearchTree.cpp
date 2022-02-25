#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() {
	size = 0;
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {

}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& a) {

}

bool BinarySearchTree::isEmpty() const {
	return (root == NULL);
}

bool BinarySearchTree::isFull() const {
	TreeNode* ptr = new TreeNode;
	if (ptr == NULL) {
		return true;
	}
	delete ptr;
	return false;
}

int BinarySearchTree::getSize() const {
	return getSize(root);
}

int BinarySearchTree::getSize(TreeNode* node) const {
	if (node == NULL) {
		return 0;
	}
	else {
		return (1 + getSize(node->left) + getSize(node->right));
	}
}

//pre: tree is not empty
ItemType BinarySearchTree::getRoot() const {
	return root->data;
}

bool BinarySearchTree::searchNode(ItemType a) const {
	return searchItem(a, root);
}

bool BinarySearchTree::searchItem(ItemType a, TreeNode* node) const {
	if (node == NULL) {
		return false;
	}
	else if (node->data == a) {
		return true;
	}
	else {
		if (node->data > a) {
			return searchItem(a, node->left);
		}
		else{
			return searchItem(a, node->right);
		}
	}
}

void BinarySearchTree::insertNode(ItemType a) {
	//if (root == NULL) {
	//	TreeNode* temp = new TreeNode;
	//	temp->data = a;
	//	root = temp;
	//}
	//else {
		insertItem(a, root);
	//}
}

void BinarySearchTree::insertItem(ItemType a, TreeNode* &node) {
	//if (a < node->data) {	//Go left
	//	if (node->left == NULL) {
	//		TreeNode* temp = new TreeNode;
	//		temp->data = a;
	//		node->left = temp;
	//	}
	//	else {
	//		insertItem(a, node->left);
	//	}
	//}
	//else if (a > node->data) {	//Go right
	//	if (node->right == NULL) {
	//		TreeNode* temp = new TreeNode;
	//		temp->data = a;
	//		node->right = temp;
	//	}
	//	else {
	//		insertItem(a, node->right);
	//	}
	//}

	if (node == NULL) {
		node = new TreeNode;
		node->data = a;
		node->left = NULL;
		node->right = NULL;
	}
	else if (node->data > a) {
		insertItem(a, node->left);
	}
	else {
		insertItem(a, node->right);
	}
}

void BinarySearchTree::deleteNode(ItemType a) {
	deleteItem(a, root);
	size--;
}

void BinarySearchTree::deleteItem(ItemType a, TreeNode*& node) {	//No children, 1 child, 2 children
	if (node->data > a) {
		deleteItem(a, node->left);
	}
	else if (node->data < a ){
		deleteItem(a, node->right);
	}
	else {
		if (node->left == NULL && node->right == NULL) {	//No children
			delete node;
			node = NULL;
		}
		else if (node->left != NULL && node->right == NULL) {	//One child, left
			TreeNode* temp = node->left;
			delete node;
			node = temp;
		}
		else if (node->right != NULL && node->left == NULL) {	//One child, right
			TreeNode* temp = node->right;
			delete node;
			node = temp;
		}
		else {	//Two children
			TreeNode* largest = node->left;
		
			while (largest->right != NULL) {	//Finds most right val in left subrtree
				largest = largest->right;
			}
			//largest->right = node->right;
			node->data = largest->data;
			deleteItem(largest->data, largest);
		}
	}
}

void BinarySearchTree::printBSTpreOrder() const {	//root first
	printPreOrder(root);
}

void BinarySearchTree::printPreOrder(TreeNode* node) const {
	if (node == NULL) {
		return;
	}
	std::cout << node->data << ' ';
	printPreOrder(node->left);
	printPreOrder(node->right);
}

void BinarySearchTree::printBSTinOrder() const {	//root middle
	printInOrder(root);
}

void BinarySearchTree::printInOrder(TreeNode* node) const {
	if (node == NULL) {
		return;
	}
	//if (node->right == NULL && node->left == NULL) {
	//	std::cout << node->data << ' ';
	//}
	printInOrder(node->left);
	std::cout << node->data << ' ';
	printInOrder(node->right);
}

void BinarySearchTree::printBSTpostOrder() const {	//root last
	printPostOrder(root);
}

void BinarySearchTree::printPostOrder(TreeNode* node) const {
	if (node == NULL) {
		return;
	}
	printPostOrder(node->left);
	printPostOrder(node->right);
	std::cout << node->data << ' ';
}

void BinarySearchTree::operator= (const BinarySearchTree& a) {

}