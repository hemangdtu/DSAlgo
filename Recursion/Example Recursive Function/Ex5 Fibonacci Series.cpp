#include <iostream>

using namespace std;

void fibonacci (int cases, int f=0, int s=1)
{
    int t;
    static int n = 0;
    if (cases == 0)
    {
        cout<<"0";
        return;
    }
    else if (cases == 1)
    {
        cout<<"1";
        return;
    }
    if(n == 0)
        cout<<"0 1 ";
    t = f + s;
    cout << t << " ";
    n++;
    if(n<cases-1)
        fibonacci(cases, s, t);
}

int fibno (int n)
{
    if (n<=1)
        return n;
    return fibno(n-2)+fibno(n-1);
}

int upgradedfibonacci (int n)
{
    static int arr[10];
    for(int i=0; i<10; i++)
        arr[i]=-1;
    if(n<=1)
    {
        arr[n]=n;
        return n;
    }
    if(arr[n-2]==-1)
        arr[n-2]=upgradedfibonacci(n-2);
    if(arr[n-1]==-1)
        arr[n-1]=upgradedfibonacci(n-1);
    return upgradedfibonacci(n-2)+upgradedfibonacci(n-1);
}

int main()
{
    int n;
    cin>>n;
    fibonacci(n);   //Printing the whole series
    cout<<endl<<fibno(n); //Excessive Recursion O(2^n)
    cout<<endl<<upgradedfibonacci(n);   //Memoization O(n)
    return 0;
}
