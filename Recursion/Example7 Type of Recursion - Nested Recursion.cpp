/*NESTED RECURSION
A recursive function calling itself with a recursive call as a parameter*/
#include<iostream>
using namespace std;

int func1 (int n)
{
    if(n>100)
    {
        return n-10;
    }
    else
    {
            return func1(func1(n+11));
    }
}

int main()
{
    cout<<func1(95);
    return 0;
}
//For any value <=100 the output will be the same (91)
//For any value >100 the output will be different
