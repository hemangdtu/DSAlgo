#include <bits/stdc++.h>
using namespace std;

bool balancedParenthesis(char *expression)
{
	stack<char> s;
	for(int i = 0; expression[i] != '\0'; i++)
		if(expression[i] == '(')
			s.push('(');
		else if(expression[i] == ')')
			if(s.empty() || s.top() != '(')
				return false;
			else
				s.pop();
	return s.size() == 0;
}

int main()
{
	char s[] = "((a+b)*(a-b))";

	if(balancedParenthesis(s))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";

	char t[] = "((a+b)*(a-b)))";

	if(balancedParenthesis(t))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";

	return 0;
}