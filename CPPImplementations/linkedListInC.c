#include<stdio.h>
#include<stdlib.h>
void pushFront(int i);// pushes or inserts item in the front of the list
int topFront(); //returns front item i.e first item in the linked list
void traverse();// displays the current list
void popFront();//deletes the front element of linked list
void pushBack(int i);
int topBack();
void popBack();   
struct node
{
	int data;
	struct node * next;
};
struct node * head = NULL;
struct node *tail = NULL;
void pushBack(int i)
{
	struct node * newNode2 =(struct node *)malloc(sizeof(struct node));
	newNode2->data=i;
	newNode2->next=NULL;
	if(tail!=NULL)
		tail->next=newNode2;
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
}
void popFront()
{
	if (head==NULL)
		printf("No element to pop\n");
	head=head->next;
	if(head==NULL)
		tail=NULL;
}
void popBack()
{
	struct node *ptr=head;
	if(head==NULL)
		printf("No element to pop\n");
	if(head->next==NULL)
	{
		head=NULL;
		tail=NULL;
	}
	while(ptr->next->next != NULL)
	{
		ptr=ptr->next;
		
	}
	tail=ptr;
	ptr->next=NULL;
}
void traverse()
{
	if (head==NULL)
		printf("empty list. add elements");
	struct node * ptr =  head;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}
int topFront()
{
	return head->data;
}
int topBack()
{
	return tail->data;
}
int main()
{
	/*
	PushFront(1);
	PushFront(2);
	PushFront(3);
	traverse();
	printf("\n");
	popFront();
	traverse();
	printf("\n");
	PushFront(3);
	traverse();
	printf("\n");
	pushBack(1);
	pushBack(2);
	pushBack(3);
	//printf("%d\n",TopFront());
	traverse();
	popBack();
	printf("\n");
	traverse();
	popBack();
	popFront();
	printf("\n");
	traverse();
	popBack();
	popBack();
    traverse();
	popFront();
	traverse();
	printf("\n"); */
	for(int i=1;i<=10;i++)
		pushBack(i);
	traverse();
	printf("\n");
	for(int i=0;i<4;i++)
		popBack();
	traverse();
	printf("\n");
	for(int i=0;i<5;i++)
		popBack();
	traverse();
	popFront();
	traverse();
	
	
	
	
	return 0;
}
