/*INDIRECT RECURSION
More than one function present in a code to call each other in a circular fashion
A->B->C->D->A*/
#include<iostream>
using namespace std;

void func2 (int);
void func1 (int n)
{
    if(n>0)
    {
        cout<<n<<endl;
        func2(n-1);
    }
}
void func2 (int n)
{
    if(n>1)
    {
        cout<<n<<endl;
        func1(n/2);
    }
}
int main()
{
    func1(20);
    return 0;
}
