#include<bits/stdc++.h>
using namespace std;

class ProblemStack{
private:
	vector<int> stack;
	vector<int> minStack;
	vector<int> maxStack;

public:
	int top()
	{
		return stack[stack.size()-1];
	}

	void push(int data)
	{
		int current_min = data;
		int current_max = data;

		stack.push_back(data);

		if(minStack.size())
		{
			current_min = min(minStack[minStack.size()-1], data);
			current_max = max(maxStack[maxStack.size()-1], data);
		}
		minStack.push_back(current_min);
		maxStack.push_back(current_max);
	}

	int getMax()
	{
		return maxStack[maxStack.size()-1];
	}

	int getMin()
	{
		return minStack[minStack.size()-1];
	}

	bool empty()
	{
		return stack.size() == 0;
	}

	void pop()
	{
		minStack.pop_back();
		maxStack.pop_back();
		stack.pop_back();
	}
};

int main()
{
	ProblemStack s;
	
	for(int i = 1; i<5; i++)
		s.push(i);
	for(int i = 5; i>0; i--)
		s.push(i);

	cout<<s.getMax()<<" "<<s.getMin();

	while(!s.empty())
		s.pop();
	
	s.push(1);
	cout<<"\n"<<s.getMax()<<" "<<s.getMin();

	return 0;
}