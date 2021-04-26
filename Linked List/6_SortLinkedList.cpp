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

node* MidPointLinkedList(node* head)
{
	if(head == NULL || head -> next == NULL)
		return head;
	node* slow = head;
	node* fast = head -> next;
	while((fast != NULL) && (fast -> next != NULL))
	{
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	return slow;
}

node* MergeLinkedList(node* a, node* b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	node* temp;
	if(a -> data < b -> data)
	{
		temp = a;
		temp -> next = MergeLinkedList(a -> next, b);
	}
	else
	{
		temp = b;
		temp -> next = MergeLinkedList(a, b -> next);
	}
	return temp;
}

node* SortLinkedList(node* head)
{
	// Implementing Merge Sort
	if(head == NULL || head -> next == NULL)
		return head;
	
	node* mid = MidPointLinkedList(head);
	node* first = head;
	node* second = mid -> next;
	mid -> next = NULL;

	first = SortLinkedList(first);
	second = SortLinkedList(second);

	return MergeLinkedList(first, second);
}

int main()
{
	node* HEAD = NULL;
	cin >> HEAD;
	cout << HEAD;
	HEAD = SortLinkedList(HEAD);
	cout << HEAD;
	return 0;
}