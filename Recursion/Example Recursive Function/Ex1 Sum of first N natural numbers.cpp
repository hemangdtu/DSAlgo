#include<iostream>
using namespace std;

int sumfunc (int n)
{
    if(n>0)
        return sumfunc(n-1)+n;  // return sumfunc(n--)+n; is necessary to discuss
    else
        return 0;
}

int main()
{
    int N;
    cin>>N;
    cout<<sumfunc(N);
    return 0;
}
