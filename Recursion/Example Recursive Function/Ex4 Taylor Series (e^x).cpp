#include<iostream>
using namespace std;

double taylorseries (int x, int n)
{
    static double power=1, factorial=1;
    double r;
    if(n==0)
        return 1;
    r=taylorseries(x, n-1);
    power*=x;
    factorial*=n;
    return r + power/factorial;
}

double taylorseriesloop (int x, int n)
{
    double s = 1;
    for(;n>0;n--)
        s = 1 + (x*(s/n));
    return s;
}

double newtaylorseries (int x, int n)
{
    static double s=1;
    if(n==0)
        return s;
    s = 1 + (x*(s/n));
    return newtaylorseries(x, n-1);
}

int main()
{
    int N, M;
    cin>>N>>M;
    cout<<taylorseries(N, M)<<endl;
    cout<<taylorseriesloop(N, M)<<endl<<newtaylorseries(N, M);
    return 0;
}
