#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void pushFront(int i);// pushes or inserts item in the front of the list
int topFront(); //returns front item i.e first item in the linked list
void traverse();// displays the current list
void popFront();//deletes the front element of linked list
void pushBack(int i);
int topBack();
void popBack();
bool empty();
struct node * find(int key);
bool boolfind(int key);
void erase(int key);
//void addAfter(struct node * node1,int key);
void addBefore(int beforekey,int key);
void addAfter(int afterkey,int key);
struct node
{
	int data;
	struct node * next;
	struct node * prev;
};
struct node* head = NULL;
struct node* tail = NULL;
void pushBack(int i)
{
	struct node * newNode2 =(struct node *)malloc(sizeof(struct node));
	newNode2->data=i;
	newNode2->next=NULL;
	if(tail!=NULL){
		tail->next=newNode2;
		newNode2->prev=tail;
	}
		
	tail=newNode2;
	if(head==NULL)
		head=tail;
		
	
}
void pushFront(int i)
{
	struct node * newNode =(struct node*)malloc(sizeof(struct node));
	newNode->data=i;
	newNode->next=head;
	head=newNode;
	if(tail==NULL)
		tail = head;
	else
		newNode->next->prev=newNode;
	newNode->prev=NULL;
}
bool empty()
{
	return head==NULL ;
}

void popFront()
{
	if (empty()){
		printf("No element to pop\n");
		return;
	}
		
	head=head->next;
	if(head!=NULL)
		head->prev=NULL;
	if(head==NULL)
		tail=NULL;
}
bool boolfind(int key)
{
	if(head == NULL)
		return false;
	struct node * boolfinder = head;
	
	while(boolfinder->next!=NULL)
	{
		if(boolfinder->data==key)
		{
			return true;
		}
		boolfinder=boolfinder->next;
			
	}
	return false;
}
struct node *find(int key)
{
	struct node * finder= head;
	if (head==NULL)
		return NULL;
	while(finder->next!=NULL)
	{
		if(finder->data==key)
		{
			return finder;
		}
		finder=finder->next;
	}
	return NULL;
}
void erase(int key)
{
	if(boolfind(key))
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
		struct node * findererase = head->next;
		while(findererase!=NULL)
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
		printf("There is no such key to erase");
}
void popBack()
{
	if (empty()){
		printf("No element to pop\n");
		return;
	}
		
	if(head==tail)
	{
		head=NULL;
		tail=NULL;
	}
	else{
		tail=tail->prev;
		tail->next=NULL;
		
	}
	
}
void traverse()
{
	if (head==NULL){
		printf("empty list. add elements");
		return;
	}
	struct node * ptr =  head;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}
/*void addAfter(struct node* node1,int key)
{
	struct node * newNode= (struct node *)malloc(sizeof(struct node));
	newNode->data=key;
	newNode->next=node1->next;
	node1->next=newNode;
	if(newNode->next==NULL)
		tail=newNode;
}*/
void addAfter(int afterkey,int key)
{
	struct node * newNode =(struct node *)malloc(sizeof(struct node));
	newNode->data=key;
	struct node * ptr = head;
	while(ptr!=NULL)
	{
		if(ptr->data==afterkey)
		{
			newNode->next=ptr->next;
			newNode->prev=ptr;
			if(newNode->next!=NULL)
				ptr->next->prev=newNode;
			ptr->next=newNode;
			if(newNode->next==NULL)
				tail=newNode;
			return;
		}
		ptr=ptr->next;
	}
	
	printf("There is no %d key to add %d key before it.",afterkey,key);
	
}
void addBefore(int keybefore,int key)
{
	
	if(head->data==keybefore)
	{
		pushFront(key);
		return;
	}
	struct node * newNode1 = (struct node*)malloc(sizeof(struct node));
    newNode1->data=key;
	struct node *ptr = head->next;
	while(ptr!=NULL)
	{
		if(ptr->data==keybefore)
		{
			newNode1->next=ptr;
			newNode1->prev=ptr->prev;
			if(newNode1->prev!=NULL)
			ptr->prev->next=newNode1;
			
			if(newNode1->prev==NULL)
				head=newNode1;
			return;
		}
		ptr=ptr->next;
	}
	printf("There is no %d key to add %d key before it.",keybefore,key);
		
	}

int topFront()
{
	if(empty())
	{
		printf("No element at the front top.\n");
		return 0;
	}
	return head->data;
}
int topBack()
{
	if(empty())
	{
		printf("No element at the back top.\n");
		return 0;
	}
	return tail->data;
}
int main()
{
	/*for(int i=10;i>=1;i--)
		pushFront(i);
	traverse();
	popFront();
	printf("\n");
    traverse();	
	for(int i=0;i<8;i++)
		popFront();
	printf("\n");
	traverse();
	//popFront();
	//popFront();
	pushBack(7);
	printf("\n");
	traverse();
	for(int i=3;i>=1;i--)
		pushBack(i);
	traverse();
	printf("\n");
	popBack();
	traverse();
	//for(int i=0;i<4;i++)
	//	popBack();
    if(boolfind(3))
		printf("\n3 present.\n");
	erase(3);
	printf("\n");
	traverse();
	erase(3);
	printf("\n");
	traverse();
	addBefore(2,3);
	printf("\n");
	traverse();*/
	/*for(int i=10;i>=1;i--)
		pushFront(i);
	traverse();
	popFront();
	printf("\n");
    traverse();	
	for(int i=0;i<8;i++)
		popFront();
	printf("\n");
	traverse();
	popFront();
	popFront();
	popBack();
	if(empty())
		printf("linked list is empty.\n");
	topBack();*/
	for(int i=0;i<4;i++)
		pushFront(i);
	traverse();
	//cout<<endl<<q.topBack()<<endl;
	popBack();
	traverse();
	
	
	
	return 0;
}
