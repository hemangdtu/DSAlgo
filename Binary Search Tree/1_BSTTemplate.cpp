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

istream& operator>>(istream &is, node*&root)
{
	root = buildBST();
	return is;
}

int main()
{
	// node* ROOT = buildBST();
	node* ROOT = NULL;
	cin>>ROOT;
	inorderPrint(ROOT);
	cout<<"\n\n";
	bfsNewline(ROOT);
	return 0;
}