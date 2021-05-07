#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> s;
	for(int i = 0; i<5; i++)
		s.push(i*i);
	while(!s.empty())
		cout<<s.top()<<" ";

	cout<<"\n";
	
	stack<char> c;
	for(char i = 'a'; i<'j'; i++)
		c.push(i);
	while(!c.empty())
	{
		cout<<c.top()<<" ";
		c.pop();
	}

	return 0;
}