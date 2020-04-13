#include<iostream>
using namespace std;

int power (int n, int m)
{
    if(m>0)
        return n * power(n, m-1);
    else
        return 1;
}

int newpower (int n, int m)
{
    if(m>0)
        if(m%2==0)
            return newpower(n*n, m/2);
        else
            return newpower(n*n, m/2)*n;
    else
        return 1;
}

int main()
{
    int N, M;
    cin>>N>>M;
    cout<<power(N, M)<<"\n"<<newpower(N, M);
    return 0;
}
