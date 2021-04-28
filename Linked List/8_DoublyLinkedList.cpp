#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* previous;
	node* next;

	node(int d)
	{
		data = d;
		previous = NULL;
		next = NULL;
	}
};

void insertHeadDoublyLinkedList(node*&head, int data)
{
	if(head == NULL)
	{
		head = new node(data);
		return;
	}
	node* n = new node(data);
	n -> previous = NULL;
	n -> next = head;
	head = n;
}

void deleteHeadDoublyLinkedList(node*&head)
{
	if(head == NULL)
		return;
	node *temp = head -> next;
	temp -> previous = NULL;
	delete head;
	head = temp;
}

void printDoublyLinkedList(node* head)
{
	while(head != NULL)
	{
		cout<<head -> data<<" -> ";
		head = head->next;
	}
	cout<<"\n";
	return;
}

int main()
{
	node* head = NULL;
	insertHeadDoublyLinkedList(head, 0);
	insertHeadDoublyLinkedList(head, 1);
	insertHeadDoublyLinkedList(head, 2);
	insertHeadDoublyLinkedList(head, 3);
	printDoublyLinkedList(head);
	insertHeadDoublyLinkedList(head, 4);
	printDoublyLinkedList(head);
	deleteHeadDoublyLinkedList(head);
	printDoublyLinkedList(head);
	return 0;
}