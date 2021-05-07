#include<bits/stdc++.h>
using namespace std;

// Stack maintains information in LIFO order.
// LIFO -> Last In First Out

/*
Real life applications :
1. Expression Evaluation and Conversion
2. Backtracking
3. Function Call
4. Parenthesis Checking
5. String Reversal
6. Syntax Parsing
7. Memory Management
*/

template<typename T>

class Stack
{
private:
	vector<T> v;

public:
	void push(T data)
	{
		v.push_back(data);
	}

	bool empty()
	{
		return v.size() == 0;
	}

	void pop()
	{
		if(!empty())
			v.pop_back();
	}

	T top()
	{
		return v[v.size()-1];
	}
};

int main()
{
	Stack<int> s;
	for(int i = 0; i<5; i++)
		s.push(i*i);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}

	cout<<"\n";
	
	Stack<char> c;
	for(char i = 'a'; i<'j'; i++)
		c.push(i);
	while(!c.empty())
	{
		cout<<c.top()<<" ";
		c.pop();
	}

	return 0;
}