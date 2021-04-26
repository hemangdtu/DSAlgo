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

int lengthLinkedList(node* head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head -> next;
	}
	return count;
}

// Insertion in a Linked List can occur at HEAD, in MIDDLE or at TAIL

void insertAtHead(node* &head, int data) // Insertion at HEAD
{
	if(head == NULL)
	{
		head = new node(data);
		return;
	}
	node *n = new node(data);
	n -> next = head;
	head = n;
}

void insertAtTail(node* &head, int data) // Insertion at TAIL
{
	if(head == NULL)
	{
		head = new node(data);
		return;
	}
	node* tail = head;
	while(tail -> next != NULL)
	{
		tail = tail -> next;
	}
	tail -> next = new node(data);
	return;
}

void insertInMiddle(node* &head, int data, int pos) // Insertion in MIDDLE
{
	if(pos == 0 || head == NULL)
	{
		insertAtHead(head, data);
		return;
	}
	else if(pos > lengthLinkedList(head))
	{
		insertAtTail(head, pos);
		return;
	}
	int samplepos = 1;
	node *temp = head;
	while(samplepos <= pos-1)
	{
		samplepos++;
		temp = temp -> next;
	}
	node* n = new node(data);
	n -> next = temp -> next;
	temp -> next = n;
	return;
}

// Deletion in a Linked List can occur at HEAD, in MIDDLE or at TAIL

void deleteHead(node* &head) // Deletion at HEAD
{
	if(head == NULL)
		return;
	node *temp = head -> next;
	delete head;
	head = temp;
}

void deleteTail(node* &head) // Deletion at TAIL
{
	if(head == NULL)
		return;
	node* tail = head;
	node* prev = tail;
	while(tail -> next != NULL)
	{
		prev = tail;
		tail = tail -> next;
	}
	delete tail;
	prev -> next = NULL;
}

void deleteInMiddle(node* head, int pos) // Deletion in MIDDLE
{
	if(head == NULL)
		return;
	else if(pos == 0)
	{
		deleteHead(head);
		return;
	}
	else if(pos > lengthLinkedList(head))
	{
		deleteTail(head);
		return;
	}
	else
	{
		int samplepos = 0;
		node* temp = head;
		node* prev = temp;
		while(samplepos <= pos-1)
		{
			samplepos++;
			prev = temp;
			temp = temp -> next;
		}
		prev -> next = temp -> next;
		delete temp;
	}
}

void printLinkedList(node* head) // Printing Linked List
{
	while(head!=NULL)
	{
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<"\n";
}

bool searchLinkedList(node* head, int key) // Searching Element in Linked List
{
	if(head == NULL)
		return false;
	while(head != NULL)
	{
		if(head -> data == key)
			return true;
		head = head -> next;
	}
	return false;
}

bool searchLinkedListRecursive(node* head, int key) // Searching Element in Linked List Recursively
{
	if(head == NULL)
		return false;
	if(head -> data == key)
		return true;
	return searchLinkedListRecursive(head -> next, key);
}

node* buildLinkedList() // Building Linked List
{
	int data;
	cin>>data;
	node* head = NULL;
	while(data!=-1)
	{
		insertAtHead(head, data);
		cin>>data;
	}
	return head;
}

node* buildLinkedListFile() // Building Linked List from File
{
	int data;
	node* head = NULL;
	while(cin>>data)
		insertAtHead(head, data);
	return head;
}

ostream& operator<<(ostream &os, node* head){
	printLinkedList(head);
	return os;
}

istream& operator>>(istream &is, node*&head){
	head = buildLinkedList();
	return is;
}

node* KthNodeEndLinkedList(node* head, int k)
{
	if(head == NULL || head -> next == NULL || k >= lengthLinkedList(head))
		return head;
	node* slow = head;
	node* fast = head -> next;
	int i = 0;
	while(fast != NULL)
	{
		fast = fast -> next;
		i++;
		if(i>k)
		{
			slow = slow -> next;
		}
	}
	return slow;
}

int main()
{
	node* HEAD = NULL;
	cin >> HEAD;
	cout << HEAD;
	node* kthNode = KthNodeEndLinkedList(HEAD, 3);
	cout<<kthNode->data;
	return 0;
}