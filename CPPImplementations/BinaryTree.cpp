#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
// defn of a node in a tree.
struct Node
	{
		string data;
	  Node* leftChild;
		Node* rightChild;
	};
class BinaryTree{
	private:
	Node* root;//points to the root of the tree.
// 	void destroy_tree(Node* leaf);
	void insert( Node* leaf, string key);
// 	Node* search(int key, Node* leaf); will be implemented latter.
	public:
	BinaryTree();//initialise binary tree.
	Node*& getTreeRoot();
// 	~BinaryTree();//to destroy binary tree.
	Node* getNewNode(string data);//to create the new node in free store and return it.
	void insert(string i);//inserts data giving priority to left child
// 	void destroy_tree();
	int Height(Node* position); //returns the height of the tree
// 	int size(); // returns the size of the tree
	void inOrderTraversal(Node* tree);
	void preOrderTraversal(Node* tree);
	void postOrderTraversal(Node* tree);
	void levelOrderTraversal(Node* tree);

};
Node*& BinaryTree::getTreeRoot( ){
    return root;
}
BinaryTree::BinaryTree(){
	 root = nullptr;
}
// BinaryTree::~BinaryTree()
// {
//     destroy_tree();
// }


Node* BinaryTree::getNewNode(string data){
    Node* newNode = new Node;
    newNode->data=data;
    newNode->leftChild=newNode->rightChild=nullptr;
    return newNode;
}


void BinaryTree::insert(string i)
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

void BinaryTree::insert(Node* leaf,string i)
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
int BinaryTree::Height(Node* position)
{
    if(position==nullptr)
      return 0;
    return 1 + max(Height(position->leftChild),Height(position->rightChild));
}

void BinaryTree::inOrderTraversal(Node* tree){
    if(tree==nullptr)
       return;
    inOrderTraversal(tree->leftChild);
    cout<<tree->data<<"\n";
    inOrderTraversal(tree->rightChild);

}
void BinaryTree::preOrderTraversal(Node* tree){
    if(tree==nullptr)
       return;
    cout<<tree->data<<"\n";
    preOrderTraversal(tree->leftChild);
    preOrderTraversal(tree->rightChild);

}

void BinaryTree::postOrderTraversal(Node* tree){
    if(tree==nullptr)
       return;
    postOrderTraversal(tree->leftChild);
    postOrderTraversal(tree->rightChild);
    cout<<tree->data<<"\n";
}

void BinaryTree::levelOrderTraversal(Node* tree){
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
	BinaryTree bst;
	Node*& tree = bst.getTreeRoot();
	tree=bst.getNewNode("Les");
	tree->leftChild=bst.getNewNode("Cathy");
	tree->rightChild=bst.getNewNode("Sam");
	tree->leftChild->leftChild=bst.getNewNode("Alex");
	tree->leftChild->rightChild=bst.getNewNode("Frank");
	tree->rightChild->leftChild=bst.getNewNode("Nancy");
	tree->rightChild->rightChild=bst.getNewNode("Violet");
	tree->rightChild->rightChild->leftChild=bst.getNewNode("Tony");
	tree->rightChild->rightChild->rightChild=bst.getNewNode("Wendy");


	int h = bst.Height(tree);
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
	cout<<"\n";
	cout<<"\n";
	bst.levelOrderTraversal(tree);


	return 0;
}
