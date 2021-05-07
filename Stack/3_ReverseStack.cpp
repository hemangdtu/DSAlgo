#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s)
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

void transfer(stack<int> &s1,stack<int> &s2, int size)
{
	for (int i = 0; i < size; ++i)
	{
		s2.push(s1.top());
		s1.pop();
	}
}

void reverseStack(stack<int> &s)
{
	stack<int> helper;
	int size = s.size();

	for (int i = 0; i < size; ++i)
	{
		int x = s.top();
		s.pop();

		transfer(s, helper, size-i-1);

		s.push(x);

		transfer(helper, s, size-i-1);
	}
}

int main()
{
	stack<int> s;
	for(int i = 0; i<5; i++)
		s.push(i);
	printStack(s);
	reverseStack(s);
	cout<<"\n";

	printStack(s);

	return 0;
}