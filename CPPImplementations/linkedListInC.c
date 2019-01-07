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
		struct node * finderprev = head;
		struct node * findererase = head->next;
		while(findererase!=NULL)
		{
			if(findererase->data==key)
			{
				finderprev->next=findererase->next;
				free(findererase);
				break;
			}
			findererase=findererase->next;
			finderprev=finderprev->next;
		}
	}
	else
		printf("There is no such key to erase");
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
	struct node *ptrprev = head;
	while(ptr!=NULL)
	{
		if(ptr->data==keybefore)
		{
			newNode1->next=ptr;
			ptrprev->next=newNode1;
			return;
		}
		ptr=ptr->next;
		ptrprev=ptrprev->next;
	}
	printf("There is no %d key to add %d key before it.",keybefore,key);
		
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
		pushFront(i);
	traverse();
	
	printf("\n");
	if (find(7)!=NULL)
		printf("%d present\n",find(7)->data);
	else
		printf("key not found\n");

	
	for(int i=0;i<3;i++)
		popBack();
	traverse();
	printf("\n");
	addBefore(7,8);
	traverse();
	printf("\n");
	erase(7);
	
	for(int i=0;i<5;i++)
		popBack();
	traverse();
	printf("\n");
	addAfter(10,9);
	//popFront();
	traverse();
	//addBefore(9,10);
	//printf("\n");
	//traverse();
	
	
	
	
	return 0;
}
