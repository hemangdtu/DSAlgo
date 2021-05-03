#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void printCircularLinkedList(node* head)
{
	if(head == NULL)
	{
		cout<<"Empty!";
		return;
	}
	node* temp = head;
	while(temp -> next != head)
	{
		cout<<temp -> data<<" -> ";
		temp = temp -> next;
	}
	cout<<temp -> data<<"\n";
}

void insertAtHead(node*&head, int data)
{
	node* n = new node(data);
	node* temp = head;

	n -> next = head;
	if(temp != NULL)
	{
		while(temp -> next != head)
		{
			temp = temp -> next;
		}
		temp -> next = n;
	}
	else
	{
		n -> next = n;
	}
	head = n;
}

node* getNode(node* head, int data)
{
	node* temp = head;
	while(temp -> next != head)
	{
		if(temp -> data == data)
			return temp;
		temp = temp -> next;
	}
	if(temp -> data == data)
		return temp;
	return NULL;
}
void deletion(node*&head, int data)
{
	node* del = getNode(head, data);
	if(head -> next == head)
	{
		head = NULL;
		return;
	}
	if(del == head)
			head = head -> next;
	if(del != NULL)
	{
		node* temp = head;
		while(temp -> next != del)
		{
			temp = temp -> next;
		}
		temp -> next = del -> next;
		delete del;
	}
	else
	{
		cout<<"Error!\n";
		return;
	}
}

int main()
{
	node* HEAD = NULL;
	insertAtHead(HEAD, 10);
	insertAtHead(HEAD, 20);
	insertAtHead(HEAD, 30);
	insertAtHead(HEAD, 40);
	insertAtHead(HEAD, 50);
	insertAtHead(HEAD, 60);
	printCircularLinkedList(HEAD);
	deletion(HEAD, 30);
	printCircularLinkedList(HEAD);
	deletion(HEAD, 10);
	printCircularLinkedList(HEAD);
	deletion(HEAD, 60);
	printCircularLinkedList(HEAD);
	deletion(HEAD, 60);
	printCircularLinkedList(HEAD);
	deletion(HEAD, 50);
	printCircularLinkedList(HEAD);
	deletion(HEAD, 20);
	printCircularLinkedList(HEAD);
	deletion(HEAD, 40);
	printCircularLinkedList(HEAD);
	return 0;
}