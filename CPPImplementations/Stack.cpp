#include<iostream>
using namespace std;
class Stack{
	private:
	struct Node
	{
		int data;
	    Node* next;
		Node* prev;
	};
	Node * head;
	Node * tail;
	
	
	public:
	Stack();
	void Push(int i);// pushes or inserts item in the front of the stack
    int Top(); //returns front item i.e first item in the linked list
	int Pop();//deletes the front element of linked list
	//void pushBack(int i);
    //int topBack();
    //void popBack();
	//bool find(int key);
	//void erase(int key);
	//void addBefore(int beforekey,int key);
	//void addAfter(int afterkey,int key);
	bool empty();
	void traverse();// displays the current list
};
Stack::Stack(){
	 head = nullptr;
	 tail = nullptr;
}
void Stack::Push(int i)
{
	Node * newNode =new Node;
	newNode->data=i;
	newNode->next=head;
	head=newNode;
	if(tail==nullptr)
		tail = head;
	else
		tail->prev=newNode;
	newNode->prev=nullptr;
}
int Stack::Top()
{
	if(empty())
	{
		cout<<"No element at the front top.\n";
		return 0;
	}
	return head->data;
}
int Stack::Pop()
{
	if (empty()){
		cout<<"No element to pop.\n";
		return -1;
	}
	int t = Top();
	head=head->next;
	if(head!=nullptr)
		head->prev=nullptr;
	if(head==nullptr)
		tail=nullptr;
	return t;
}
void Stack::traverse()
{
	if (empty())
		cout<<"empty list. add elements";
	Node * ptr =  head;
	while(ptr!=nullptr)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
}
bool Stack::empty()
{
	return head==nullptr;
}
int main()
{
	Stack s;
	for (int i=0;i<5;i++)
	    s.Push(i);
	cout<<s.Top()<<endl;
	s.traverse();
	 return 0;
}