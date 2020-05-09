#include <iostream>
using namespace std;

void toh (int n, int A, int B, int C)
{
    if(n>0)
    {
        toh(n-1, A, C, B);
        cout<<"From "<<A<<" to "<<C<<endl;
        toh(n-1, B, A, C);
    }
}

int main()
{
    int num;
    cin>>num;
    toh(num, 1, 2, 3);
    return 0;
}
// Time Complexity: O(2^num)
