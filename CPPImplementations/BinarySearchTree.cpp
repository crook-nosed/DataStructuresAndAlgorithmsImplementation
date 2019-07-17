// The below implementation of binary search tree has been coded before actually learning binary search tree in that detail mainly showing the traversals(depth first and breadth first)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
// defn of a node in a tree.
struct Node
	{
		int data;
	  Node* leftChild;
		Node* rightChild;
	};
class BinarySearchTree{
	private:
	Node* root;//points to the root of the tree.
	void destroy_tree(Node* leaf);
	void insert( Node* leaf, int key);
	Node* search(Node* leaf, int key); //will be implemented latter.
	public:
	BinarySearchTree();//initialise binary tree.
	Node*& getTreeRoot();
	~BinarySearchTree();//to destroy binary tree.
	Node* getNewNode(int data);//to create the new node in free store and return it.
	void insert(int i);//inserts data giving priority to left child
	void destroy_tree();
	int Height(Node* position); //returns the height of the tree
  Node* search(int key);
// 	int size(); // returns the size of the tree
	void inOrderTraversal(Node* tree);
	void preOrderTraversal(Node* tree);
	void postOrderTraversal(Node* tree);
	void levelOrderTraversal(Node* tree);

};
Node*& BinarySearchTree::getTreeRoot( ){
    return root;
}
BinarySearchTree::BinarySearchTree(){
	 root = nullptr;
// 	 leaf = nullptr;

}
BinarySearchTree::~BinarySearchTree()
{
    destroy_tree();
}

void BinarySearchTree::destroy_tree()
{
  destroy_tree(root);
}

void BinarySearchTree::destroy_tree(Node *leaf)
{
  if(leaf!=nullptr)
  {
    destroy_tree(leaf->leftChild);
    destroy_tree(leaf->rightChild);
    delete leaf;

  }
}

Node* BinarySearchTree::search(int key)
{
  return search(root,key);
}

Node* BinarySearchTree::search(Node* leaf, int key)
{
  if(leaf!=nullptr)
  {
    if(key==leaf->data)
       return leaf;
    if(key< leaf->data)
      return search(leaf->leftChild, key);
    else
      return search(leaf->leftChild, key);
  }
  else
    return nullptr;
}

Node* BinarySearchTree::getNewNode(int data){
    Node* newNode = new Node;
    newNode->data=data;
    newNode->leftChild=newNode->rightChild=nullptr;
    return newNode;
}


void BinarySearchTree::insert(int i)
{

	if(root == nullptr)
	{
	    root =getNewNode(i);
	}
	else
	{
	    insert(root,i);
	}

}

void BinarySearchTree::insert(Node* leaf,int i)
{

 if(i< leaf->data)
  {
    if(leaf->leftChild!=nullptr)
     insert(leaf->leftChild,i);
    else
    {
      leaf->leftChild=getNewNode(i);
    }
  }
  else if(i>=leaf->data)
  {
    if(leaf->rightChild!=nullptr)
      insert(leaf->rightChild,i);
    else
    {
      leaf->rightChild=getNewNode(i);
    }
  }
}
int BinarySearchTree::Height(Node* position)
{
    if(position==nullptr)
      return 0;
    return 1 + max(Height(position->leftChild),Height(position->rightChild));
}

void BinarySearchTree::inOrderTraversal(Node* tree){
    if(tree==nullptr)
      return;
    inOrderTraversal(tree->leftChild);
    cout<<tree->data<<"\n";
    inOrderTraversal(tree->rightChild);

}
void BinarySearchTree::preOrderTraversal(Node* tree){
    if(tree==nullptr)
      return;
    cout<<tree->data<<"\n";
    preOrderTraversal(tree->leftChild);
    preOrderTraversal(tree->rightChild);

}

void BinarySearchTree::postOrderTraversal(Node* tree){
    if(tree==nullptr)
      return;
    postOrderTraversal(tree->leftChild);
    postOrderTraversal(tree->rightChild);
    cout<<tree->data<<"\n";
}

void BinarySearchTree::levelOrderTraversal(Node* tree){
  if(tree == nullptr)
    return;
  Node* node;
  queue<Node*> q;
  q.push(tree);
  while(!q.empty())
  {
    node = q.front();
    q.pop();
    cout<<node->data<<"\n";
    if(node->leftChild != nullptr)
      q.push(node->leftChild);
    if(node->rightChild != nullptr)
      q.push(node->rightChild);
  }

}

int main()
{
	BinarySearchTree bst;
	Node*& tree = bst.getTreeRoot();
	int num;
	for(int i=0; i<7; i++)
	{
	    cin>>num;
	    bst.insert(num);
	}
	int h = bst.Height(tree->leftChild);
	cout<<h<<"\n";
	cout<<"\n";
	cout<<"\n";
	bst.postOrderTraversal(tree);
	cout<<"\n";
	cout<<"\n";
	bst.preOrderTraversal(tree);
	cout<<"\n";
	cout<<"\n";
	bst.inOrderTraversal(tree);


	return 0;
}