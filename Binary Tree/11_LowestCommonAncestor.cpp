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

node* lca(node* root, int a, int b)
{
	if(root == NULL)
		return NULL;
	
	if(root -> data == a || root -> data == b)
		return root;
	
	node* leftAnswer = lca(root -> left, a, b);
	node* rightAnswer = lca(root -> right, a, b);

	if(leftAnswer != NULL && rightAnswer != NULL)
		return root;

	if(leftAnswer != NULL)
		return leftAnswer;
	return rightAnswer;
}

int main()
{
	// SAMPLE : 2 3 7 -1 -1 11 8 -1 -1 -1 4 0 5 -1 -1 6 -1 -1 1 -1 -1
	node* ROOT = buildTree();
	bfsNewline(ROOT);
	cout<<"\n"<<lca(ROOT, 4, 5) -> data;
	cout<<"\n"<<lca(ROOT, 8, 6) -> data;
	cout<<"\n"<<lca(ROOT, 8, 11) -> data;
	return 0;
}