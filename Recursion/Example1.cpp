#include<iostream>
using namespace std;
void func1 (int n)
{
    if(n>0)
    {
        cout<<n;
        func1(n-1);
    }
}
int main()
{
    int x=3;
    func1(x);
    return 0;
}
/*
void func1 (int n)
{
    if(n>0)
    {
        func1(n-1);
        cout<<n;
    }
}
int main()
{
    int x=3;
    func1(x);
    return 0;
}
*/
