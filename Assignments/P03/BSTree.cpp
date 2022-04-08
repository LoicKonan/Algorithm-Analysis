// Implementation file for binary search tree class

#include "BSTree.h"
#include<iostream>
#include<fstream>

using namespace std;

BSTree::BSTree()
{
	root = nullptr;
}


BSTree::~BSTree()
{
	destroySubtree(root);
}

// destroySubtree recursively visits and deletes each node
// from the lowest level (leaves) up
void BSTree::destroySubtree(Node *& ptr)
{
	if (!ptr)
	{
		destroySubtree(ptr->left);
		destroySubtree(ptr->right);
		delete ptr;
		ptr = nullptr;
	}
}

void BSTree::insertNode(Node * &ptr, int x)
{
	// If ptr points to nullptr, the insertion position has been found
	if (ptr == nullptr)  
    ptr = new Node(x);

	// If ptr does not point to nullptr, decide whether to traverse
	// down the left subtree or right subtree by comparing value
	// to be inserted with current node.
	else if (x <= ptr->data)			// Node should be inserted in left subtree
		insertNode(ptr->left, x);
	else											// Node should be inserted in right subtree
		insertNode(ptr->right, x);
}

// Public function that passes root to private helper function, insertNode
void BSTree::insert(int x)
{
	insertNode(root, x);
}


void BSTree::inOrder(Node * ptr) const
{
	if (ptr)  // Equivalent to if(ptr != nullptr)
	{
		inOrder(ptr->left);
		cout << ptr->data << "   ";
		inOrder(ptr->right);
	}
}

void BSTree::inOrderPrint()
{
	inOrder(root);
	cout << endl;
}

void BSTree::preOrder(Node * ptr) const
{
	if (ptr)  // same as if (ptr != nullptr)
	{
		cout << ptr->data << "   ";
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

void BSTree::preOrderPrint()
{
	preOrder(root);
	cout << endl;
}

void BSTree::postOrder(Node * ptr) const
{
	if (ptr)
	{
		postOrder(ptr->left);
		postOrder(ptr->right);
		cout << ptr->data << "   ";
	}
}

void BSTree::postOrderPrint()
{
	postOrder(root);
	cout << endl;
}

// Deletes a node using right child promotion
void BSTree::del(Node * &ptr)
{
	Node *delPtr = ptr;
	Node *attach;
	if (ptr->left == nullptr && ptr->right == nullptr) // no children
		ptr = nullptr;
	else if (ptr->right == nullptr)  // only left child
		ptr = ptr->left;
	else if (ptr->left == nullptr)  // only right child
		ptr = ptr->right;
	else  // two children
	{
		attach = ptr->right;
		while (attach->left != nullptr)
			attach = attach->left;
		attach->left = ptr->left;
		ptr = ptr->right;
	}
	delete delPtr;
}

// Recursive function that searches for node to be deleted and then
// passes the appropriate pointer to method del
void BSTree::deleteNode(Node * & ptr, int x)
{
	if (ptr)
	{
		if (ptr->data == x)
			del(ptr);
		else if (x < ptr->data)
			deleteNode(ptr->left, x);
		else
			deleteNode(ptr->right, x);
	}
}

// Public function that passes root to private helper function, deleteNode
void BSTree::deleteItem(int x)
{
	deleteNode(root, x);
}

void BSTree::deleteAll()
{
	destroySubtree(root);
}
bool BSTree::searchItem(Node * ptr, int x)
{
	if (ptr)
	{
		if (x == ptr->data)
			return true;
		else if (x < ptr->data)
			return searchItem(ptr->left, x);
		else
			return searchItem(ptr->right, x);
	}
	return false;
}


bool BSTree::search(int x)
{
	return searchItem(root, x);
}

void BSTree::GraphVizGetIds(Node *nodePtr, ofstream &VizOut){
	if (nodePtr){
		GraphVizGetIds(nodePtr->left, VizOut);
		VizOut << " node" << nodePtr->data << " [label=\"" << nodePtr->data << "\"];" << endl;
		GraphVizGetIds(nodePtr->right, VizOut);
	}
}


void BSTree::GraphVizMakeConnections(Node *nodePtr, ofstream &VizOut){
	if (nodePtr){
		if (nodePtr->left)
			VizOut << "  node" << nodePtr->data << "->" << " node" << nodePtr->left->data << endl;
		if (nodePtr->right)
			VizOut << "  node" << nodePtr->data << "->" << " node" << nodePtr->right->data << endl;
		GraphVizMakeConnections(nodePtr->left, VizOut);
		GraphVizMakeConnections(nodePtr->right, VizOut);
	}
}

void BSTree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename.c_str());
	VizOut << "digraph g { \n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "} \n";
	VizOut.close();
}
