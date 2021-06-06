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

node* deleteElementInBST(node* root, int element)
{
	if(root == NULL)
		return NULL;
	else if(element < root -> data)
	{
		root -> left = deleteElementInBST(root -> left, element);
		return root;
	}
	else if(element > root -> data)
	{
		root -> right = deleteElementInBST(root -> right, element);
		return root;
	}
	else
	{
		if(root -> left == NULL && root -> right == NULL) // 0 children
		{
			delete root;
			return NULL;
		}
		if(root -> left != NULL && root -> right == NULL) // 1 child
		{
			node* temp = root -> left;
			delete root;
			return temp;
		}
		if(root -> left == NULL && root -> right != NULL) // 1 child
		{
			node* temp = root -> right;
			delete root;
			return temp;
		}

		node* replace = root -> right;	// 2 children
		while(replace -> left != NULL)	// Finding inorder successor in right sub tree
			replace = replace -> left;
		root -> data = replace -> data;
		root -> right = deleteElementInBST(root -> right, replace -> data);
		return root;
	}
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

	int deleteElement;
	cin >> deleteElement;

	cout<<"\n\n";
	ROOT = deleteElementInBST(ROOT, deleteElement);
	bfsNewline(ROOT);
	return 0;
}