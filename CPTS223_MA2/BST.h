#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST() {
	    bomb (_root);
	}

	void bomb(Node<T>* pTree)
	{
		if(pTree->left != nullptr)
		{
			bomb(pTree->left);
		}
		if(pTree->right != nullptr)
		{
			bomb(pTree->right);
		}
		delete pTree;
	}


	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */
	void printLevelOrder() {
		int h = hieght()

		for(int i = 0; i <= h; i++)
		{
			printLevel(this->_root, i);
			cout << endl;
		}
	}

	void printLevel(Node<T>* pTree, int level)
	{
		if (pTree = NULL)
			{
				return;
			}
			if (level == 1)
			{
				cout << pTree->value << ' ';
			}
			else if (level > 1)
			{
				printLevel(pTree->left, level-1);
				printLevel(pTree->right, level-1);
			}
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath() {
		cout << findMaxPath(_root, INT_MIN) << ' ';
	}

	int findMaxPath(Node* pTree, int& res)
	{
		if(pTree == NULL)
		{
			return;
		}

		int left = findMaxPath(pTree->left, res);
		int right = findMaxPath(pTree->right, res);

		int max_single = max(max(1, r) + pTree->value, pTree->value);

		int max_top = max(max_single, 1 + r + pTree->value);

		res = max(res, max_top);

		return max_single;
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */
	bool contains(T value) {

		Node<T>* pTree;
		pTree = this->_root;

		if (this->_root == NULL)
		{
			return 0;
		}

		if (this->_root->value == value)
		{
			return 1;
		}

		// Search left tree
		
		if (i < height())
		{
			pTree->left;
			bool left = contains(value);
			int i = 0;
		}
		if(left == 1)
		{
			return 1;
		} 
		
		// Search Right Tree
		
		if (j < height())
		{
			j++;
			pTree->right;
			bool right = contains(value);
			int j = 0;
		}

		return right;
	}
};

#endif

