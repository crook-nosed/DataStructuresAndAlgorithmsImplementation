#include<stdio.h>
#include<stdlib.h>
void PushFront(int i);// pushes or inserts item in the front of the list
int TopFront(); //returns front item i.e first item in the linked list
void traverse();// displays the current list
void popFront();//deletes the front element of linked list
void pushBack(int i);
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
void PushFront(int i)
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
void traverse()
{
	struct node * ptr =  head;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}
int TopFront()
{
	return head->data;
}
int main()
{
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
	return 0;
}
