/*TAIL RECURSION
Recursive call is the last statement in a function*/
#include<iostream>
using namespace std;
/*
void func1 (int n)
{
    if(n>0)
    {
        cout<<n;
        func1(n-1); //func1(n-1)+n; is not a tail recursion
                    //as all tasks are not performed at or before calling time.
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
void func1 (int n)
{
    while(n>0)
    {
        cout<<n;
        n--;
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
