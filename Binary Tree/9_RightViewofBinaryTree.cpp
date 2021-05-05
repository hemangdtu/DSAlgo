#include<iostream>
#include<queue>
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

int heightTree(node* root)
{
	if(root == NULL)
		return 0;
	int ls = heightTree(root -> left);
	int rs = heightTree(root -> right);
	return max(ls, rs) + 1;
}

void printkthLevelTree(node* root, int k)
{
	if(root == NULL)
		return;
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printkthLevelTree(root -> left, k-1);
	printkthLevelTree(root -> right, k-1);
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

void allLevelPrintTree(node* root) // Worst Case Time Comp : O(N^2) -> Skew Tree
{
	if(root == NULL)
		return;
	int height = heightTree(root);
	for(int i = 1; i<= height; i++)
	{
		printkthLevelTree(root, i);
		cout<<"\n";
	}
}

void bfs(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* f = q.front();
		cout<<f -> data<<", ";
		q.pop();
		if(f -> left)
			q.push(f -> left);
		if(f -> right)
			q.push(f -> right);
	}
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
}

class BalancedPair{
public:
	int height;
	bool balanced;
};

BalancedPair checkHeightBalancedTree(node* root)
{
	BalancedPair p;
	if(root == NULL)
	{
		p.height = 0;
		p.balanced = true;
		return p;
	}
	BalancedPair left = checkHeightBalancedTree(root -> left);
	BalancedPair right = checkHeightBalancedTree(root -> right);

	p.height = max(left.height, right.height) + 1;
	if(abs(left.height - right.height) <= 1 && left.balanced && right.balanced)
		p.balanced = true;
	else
		p.balanced = false;
	return p;
}

node* buildTreeFromArray(int *arr, int s, int e)
{
	if(s > e)
		return NULL;
	int mid = (s + e)/2;
	node* root = new node(arr[mid]);
	root -> left = buildTreeFromArray(arr, s, mid -1);
	root -> right = buildTreeFromArray(arr, mid + 1, e);
	return root;
}

void rightView(node* root)
{}

int main()
{
	// SAMPLE : 2 3 7 -1 -1 11 8 -1 -1 -1 4 0 5 -1 -1 6 -1 -1 1 -1 -1
	return 0;
}