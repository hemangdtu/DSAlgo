#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* insertInBST(node* root, int d)
{
	if(root == NULL)
		return new node(d);

	if(d > root -> data)
		root -> right = insertInBST(root -> right, d);
	else
		root -> left = insertInBST(root -> left, d);

	return root;
}

node* buildBST()
{
	int d;
	cin >> d;
	
	node* root = NULL;

	while(d != -1)
	{
		root = insertInBST(root, d);
		cin>>d;
	}
	return root;
}

void bfsNewline(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* f = q.front();
		if(f == NULL)
		{
			cout<<"\n";
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout<<f -> data<<", ";
			q.pop();

			if(f -> left)
				q.push(f -> left);
			if(f -> right)
				q.push(f -> right);
		}
	}
	return;
}

void inorderPrint(node* root)
{
	if(root == NULL)
		return;
	inorderPrint(root -> left);
	cout<<root->data<<", ";
	inorderPrint(root -> right);
}

bool checkElementInBST(node* root, int element)
{
	if(root == NULL)
		return false;
	if(root -> data == element)
		return true;

	if(element > root -> data)
		return checkElementInBST(root -> right, element);
	return checkElementInBST(root -> left, element);
}

istream& operator>>(istream &is, node*&root)
{
	root = buildBST();
	return is;
}

int main()
{
	// 5 3 7 1 6 8 -1
	// node* ROOT = buildBST();
	node* ROOT = NULL;
	cin>>ROOT;
	inorderPrint(ROOT);
	cout<<"\n\n";
	
	int searchElement;
	cin >> searchElement;
	if(checkElementInBST(ROOT, searchElement))
		cout << "Element is present!";
	else
		cout << "Element is absent!";
	return 0;
}