#include <bits/stdc++.h>
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

void insertSorted(stack<int>& testStack, int element)
{
	if(testStack.empty() || element > testStack.top())
		testStack.push(element);
	else
	{
		int temp = testStack.top();
		testStack.pop();
		insertSorted(testStack, element);
		testStack.push(temp);
	}
}

void sortStack(stack<int>& testStack)
{
	if(!testStack.empty())
	{
		int temp = testStack.top();
		testStack.pop();
		sortStack(testStack);
		insertSorted(testStack, temp);
	}
}

int main()
{
	stack<int> s;

	s.push(-1);
	s.push(100);
	s.push(700);
	s.push(-1000);
	s.push(2);
	s.push(0);
	
	printStack(s);
	sortStack(s);
	printStack(s);
    return 0;
}