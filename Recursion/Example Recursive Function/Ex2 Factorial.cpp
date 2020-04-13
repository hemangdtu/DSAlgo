#include<iostream>
using namespace std;

unsigned long long factorial (int n)
{
    if(n==0)
        return 1;
    else if (n<0)
    {
        cout<<"ERROR!";
        return 0;
    }
    else
    {
        return factorial(n-1)*n;
    }
}

int main()
{
    int N;
    unsigned long long res;
    cin>>N;
    res = factorial(N);
    if(res!=0)
        cout<<res;
    return 0;
}
