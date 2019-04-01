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
bool empty();
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
bool empty()
{
	return head==NULL;
}
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
	if(tail==NULL)//this represents the case when linked list was empty at the beginning so both head=tail=NULL but as now the new node has been added it is only natural for tail to point the only last element in the list which is the new node just added which is pointed to by head.
		tail = head;//Thats why tail=head
}
void popFront()
{
	if (empty()){
		printf("No element to pop\n");
		return;
	}
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
/*struct node *find(int key)
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
}*/
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
	if(empty()){
		printf("No element to pop\n");
		return;
	}
	struct node *ptr=head;
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
	if (empty())
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

	for(int i=10;i>=1;i--)
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
	topBack();
	return 0;
}
