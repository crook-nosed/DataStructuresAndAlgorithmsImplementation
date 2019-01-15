#include<iostream>
using namespace std;
class Queue{
	private:
	struct Node
	{
		int data;
	    Node* next;
	};
	Node * head;
	Node * tail;
	
	
	public:
	Queue();
	void Enqueue(int i);// pushes or inserts item in the front of the stack
    int Dequeue(); //returns front item i.e first item in the linked list
	int TopBack();//deletes the front element of linked list
	//void pushBack(int i);
    //int topBack();
    //void popBack();
	//bool find(int key);
	//void erase(int key);
	//void addBefore(int beforekey,int key);
	//void addAfter(int afterkey,int key);
	bool Empty();
	void traverse();// displays the current list
};
Queue::Queue(){
	 head = nullptr;
	 tail = nullptr;
}
void Queue::Enqueue(int i)
{
	Node * newNode =new Node;
	newNode->data=i;
	newNode->next=head;
	head=newNode;
	if(tail==nullptr)
		tail = head;
}
int Queue::TopBack()
{
	if(Empty())
	{
		cout<<"No element at the back top.\n";
		return 0;
	}
	return tail->data;
}
int Queue::Dequeue()
{
	if(Empty()){
		cout<<"No element to pop\n";
		return -1;
	}
	int t= TopBack();
	Node *ptr=head;
	if(head->next==nullptr)
	{
		head=nullptr;
		tail=nullptr;
	}
	while(ptr->next->next != nullptr)
	{
		ptr=ptr->next;
		
	}
	tail=ptr;
	ptr->next=nullptr;
	return t;
}
void Queue::traverse()
{
	if (Empty())
		cout<<"empty list. add elements";
	Node * ptr =  head;
	while(ptr!=nullptr)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
}
bool Queue::Empty()
{
	return head==nullptr;
}
int main()
{
	Queue q;
	for(int i=0;i<4;i++)
		q.Enqueue(i);
	q.traverse();
	cout<<endl<<q.Dequeue()<<endl;
	q.traverse();
	 return 0;
}