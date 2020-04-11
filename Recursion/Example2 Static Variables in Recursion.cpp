#include<iostream>
using namespace std;
/*
//WITHOUT STATIC VARIABLE
int func1 (int n)
{
    if(n>0)
    {
        return (func1(n-1)+n);
    }
    return 0;
}
int main()
{
    int x=5;
    cout<<func1(x);
    return 0;
}
*/
/*
int func1 (int n)
{
    static int x = 0;
    if(n>0)
    {
        x++;
        return (func1(n-1)+x);
    }
    return 0;
}
int main()
{
    int x=5;
    cout<<func1(x);
    return 0;
}
*/
/*
int x=0;
int func1 (int n)
{
    if(n>0)
    {
        x++;
        return (func1(n-1)+x);
    }
    return 0;
}
int main()
{
    int x=5;
    cout<<func1(x)<<endl;
    cout<<func1(x);
    return 0;
}
*/
