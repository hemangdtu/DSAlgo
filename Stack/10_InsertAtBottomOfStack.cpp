#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s)
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

stack<int> insertAtBottom(stack<int> s, int data)
{
	if(s.empty())
		s.push(data);
	else
	{
		int temp = s.top();
		s.pop();
		s = insertAtBottom(s, data);
		s.push(temp);
	}
	return s;
}

int main()
{
	stack<int> s;
	for(int i = 0; i<6; i++)
		s.push(i);
	printStack(s);
	s = insertAtBottom(s, 6);
	printStack(s);
	s = insertAtBottom(s, -1);
	printStack(s);
	return 0;
}