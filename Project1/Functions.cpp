/*
	Badajoz, Seve

	CS A200
	May 7, 2018

	Lab 06
*/

#include "BST.h"


// Definition function insert (non-recursive) 
void BST::insert(int newData) {
	if (root != nullptr) {
		Node * curr = root;
		bool exists = false;
		while (!exists) {
			if (newData < curr->data) {
				if (curr->llink != nullptr)
					curr = curr->llink;
				else {
					curr->llink = new Node;
					curr->llink->data = newData;
					exists = true;
				}
			}
			else if (newData > curr->data) {
				if (curr->rlink != nullptr)
					curr = curr->rlink;
				else {
					curr->rlink = new Node;
					curr->rlink->data = newData;
					exists = true;
				}
			}
			else {
				cout << "The item to insert is already in the list – duplicates are not allowed." << endl;
				exists = true;
			}
		}
	}
	else {
		root = new Node;
		root->data = newData;
	}
}

// Definition function totalNodes
int BST::totalNodes() const {
	if (root != nullptr)
		return totalNodes(root);
	else return 0;
}
// Definition function totalNodes (recursive)
int BST::totalNodes(const Node * node) const {
	if (node != nullptr)
		return 1 + totalNodes(node->llink) + totalNodes(node->rlink);
	else return 0;
}
// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const {
	if (root != nullptr)
		preorderTraversal(root);
	else cerr << "Attempted to traverse a non-existing tree.";
}
// Definition overloaded function preorderTraversal (recursive)
void BST::preorderTraversal(const Node * node) const {
	if (node != nullptr) {
		cout << node->data << " ";
		preorderTraversal(node->llink);
		preorderTraversal(node->rlink);
	}
}
// Definition overloaded function postorderTraversal
void BST::postorderTraversal() const {
	if (root != nullptr)
		postorderTraversal(root);
	else cerr << "Attempted to traverse a non-existing tree.";
}
// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node * node) const {
	if (node != nullptr) {
		postorderTraversal(node->llink);
		postorderTraversal(node->rlink);
		cout << node->data << " ";
	}
}
