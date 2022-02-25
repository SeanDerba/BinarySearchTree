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
	return searchNode(a, root);
}

bool BinarySearchTree::searchNode(ItemType a, TreeNode* node) const {
	if (node == NULL) {
		return false;
	}
	else if (node->data == a) {
		return true;
	}
	else {
		if (node->data > a) {
			return searchNode(a, node->left);
		}
		else{
			return searchNode(a, node->right);
		}
	}
}

void BinarySearchTree::insertNode(ItemType a) {
	if (root == NULL) {
		TreeNode* temp = new TreeNode;
		temp->data = a;
		root = temp;
	}
	else {
		insertNode(a, root);
	}
}

void BinarySearchTree::insertNode(ItemType a, TreeNode* &node) {
	if (a < node->data) {	//Go left
		if (node->left == NULL) {
			TreeNode* temp = new TreeNode;
			temp->data = a;
			node->left = temp;
		}
		else {
			insertNode(a, node->left);
		}
	}
	else if (a > node->data) {	//Go right
		if (node->right == NULL) {
			TreeNode* temp = new TreeNode;
			temp->data = a;
			node->right = temp;
		}
		else {
			insertNode(a, node->right);
		}
	}
}

void BinarySearchTree::deleteNode(ItemType a) {

}

void BinarySearchTree::printBSTpreOrder() const {

}

void BinarySearchTree::printBSTinOrder() const {

}

void BinarySearchTree::printBSTpostOrder() const {

}

void BinarySearchTree::operator= (const BinarySearchTree& a) {

}