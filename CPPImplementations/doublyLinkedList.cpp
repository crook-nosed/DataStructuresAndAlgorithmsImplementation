#include <iostream>
using namespace std;
class DList{
	private:
	struct Node
	{
		int data;
	    Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
	public:
	DList();
	void pushFront(int i);// pushes or inserts item in the front of the list
    int topFront(); //returns front item i.e first item in the linked list
	void popFront();//deletes the front element of linked list
	void pushBack(int i);
    int topBack();
    void popBack();
	bool find(int key);
	void erase(int key);
	void addBefore(int beforekey,int key);
	void addAfter(int afterkey,int key);
	bool empty();
	void traverse();// displays the current list
};
DList::DList(){
	 head = nullptr;
	 tail = nullptr;
}
void DList::pushFront(int i)
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
int DList::topFront()
{
	if(empty())
	{
		cout<<"No element at the front top.\n";
		return 0;
	}
	return head->data;
}
void DList::popFront()
{
	if (empty()){
		cout<<"No element to pop.\n";
		return;
	}
	head=head->next;
	if(head!=nullptr)
		head->prev=nullptr;
	if(head==nullptr)
		tail=nullptr;
	
}
void DList::traverse()
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
bool DList::empty()
{
	return head==nullptr;
}
int DList::topBack()
{
	if(empty())
	{
		cout<<"No element at the back top.\n";
		return 0;
	}
	return tail->data;
	
}
void DList::popBack()
{
	if (empty()){
		printf("No element to pop\n");
		return;
	}
		
	tail=tail->prev;
	if(tail!=nullptr)
		tail->next=nullptr;
	if(tail==nullptr)
		head=nullptr;
	
}
void DList::pushBack(int i)
{
	Node * newNode2 =new Node;
	newNode2->data=i;
	newNode2->next=nullptr;
	if(tail!=nullptr){
		tail->next=newNode2;
		newNode2->prev = tail;
	}
	tail=newNode2;
	if(head==nullptr)
		head=tail;
	
	
}
bool DList::find(int key)
{
	if(head == nullptr)
		return false;
	Node* boolfinder = head;
	
	while(boolfinder->next!=nullptr)
	{
		if(boolfinder->data==key)
		{
			return true;
		}
		boolfinder=boolfinder->next;
			
	}
	return false;
	
}
void DList::erase(int key)
{
	if(find(key))
	{
		if (head->data==key)
		{
			popFront();
			return;
		}
		if(tail->data==key)
		{
			popBack();
			return;
		}
		//struct node * finderprev = head;
		Node* findererase = head->next;
		while(findererase!=nullptr)
		{
			if(findererase->data==key)
			{
				findererase->prev->next=findererase->next;
				findererase->next->prev=findererase->prev;
				free(findererase);
				break;
			}
			findererase=findererase->next;
			//finderprev=finderprev->next;
		}
	}
	else
		cout<<"There is no such key to erase";
	
}
void DList::addAfter(int afterkey,int key)
{
	Node * newNode =new Node;
	newNode->data=key;
	Node * ptr = head;
	while(ptr!=nullptr)
	{
		if(ptr->data==afterkey)
		{
			newNode->next=ptr->next;
			newNode->prev=ptr;
			if(newNode->next!=nullptr)
				ptr->next->prev=newNode;
			ptr->next=newNode;
			if(newNode->next==NULL)
				tail=newNode;
			return;
		}
		ptr=ptr->next;
	}
	
	cout<<"There is no "<<afterkey<<" key to add "<<key<<" key before it.";
	
	
}
void DList::addBefore(int keybefore,int key)
{
	
	if(head->data==keybefore)
	{
		pushFront(key);
		return;
	}
	Node * newNode1 = new Node;
    newNode1->data=key;
	Node *ptr = head->next;
	while(ptr!=nullptr)
	{
		if(ptr->data==keybefore)
		{
			newNode1->next=ptr;
			newNode1->prev=ptr->prev;
			if(newNode1->prev!=nullptr)
			ptr->prev->next=newNode1;
			
			if(newNode1->prev==nullptr)
				head=newNode1;
			return;
		}
		ptr=ptr->next;
	}
	cout<<"There is no"<<keybefore<<" key to add "<<key<<" key before it.";
		
	}
int main()
{
	DList l1;
	for(int i=10;i>=1;i--)
		l1.pushFront(i);
	l1.traverse();
	l1.popFront();
	cout<<"\n";
    l1.traverse();	
	for(int i=0;i<8;i++)
		l1.popFront();
	cout<<"\n";
	l1.traverse();
	l1.popFront();
	l1.popFront();
	l1.popBack();
	if(l1.empty())
		cout<<"linked list is empty.\n";
	l1.topBack();
	l1.popBack();
	return 0;
}