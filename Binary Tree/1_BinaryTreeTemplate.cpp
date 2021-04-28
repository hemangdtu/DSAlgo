#include<iostream>
using namespace std;

// Parents, Children, Siblings, Ancestors, Decendents, Leaf nodes

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

node* buildTree(){
	int d;
	cin>>d;
	if(d == -1)
		return NULL;
	node* root = new node(d);
	root -> left = buildTree();
	root -> right = buildTree();
	return root;
}

void preorderPrintTree(node* root) // Root -> Left Sub tree -> Right Sub tree
{
	if(root == NULL)
		return;
	cout<<root -> data<<" ";
	preorderPrintTree(root->left);
	preorderPrintTree(root->right);
}

void inorderPrintTree(node* root) // Left Sub tree -> Root -> Right Sub tree
{
	if(root == NULL)
		return;
	inorderPrintTree(root->left);
	cout<<root -> data<<" ";
	inorderPrintTree(root->right);
}

void postorderPrintTree(node* root) // Left Sub tree -> Right Sub tree -> Root
{
	if(root == NULL)
		return;
	postorderPrintTree(root->left);
	postorderPrintTree(root->right);
	cout<<root -> data<<" ";
}

int main()
{
	node* HEAD = buildTree();
	preorderPrintTree(HEAD);
	return 0;
}