/*HEAD RECURSION
Recursive call is the first statement in a function*/
#include<iostream>
using namespace std;
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
    func1(4);
    return 0;
}
//Time Complexity = O(n)
//Space Complexity = O(n)
*/
/*
CANNOT BE WRITTEN JUST BY LOOKING AT THE RECURSION PROGRAM

void func1 (int n)
{
    int i = 1;
    while(i<=n)
    {
        cout<<i;
        i++;
    }
}
int main()
{
    func1(4);
    return 0;
}
//Time Complexity = O(n)
//Space Complexity = O(1)
*/

//LOOPS ARE RECOMMENDED TO PERFORM TAIL RECURSSION

