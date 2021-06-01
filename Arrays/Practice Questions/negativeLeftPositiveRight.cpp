#include <bits/stdc++.h>
using namespace std;

void orderingFunction(int* arr, int n)
{
    int negative = 0;
    for (int positive = 0; positive < n; positive++)
    {
        if (0 > arr[positive])
        {
            if (positive != negative)
                swap(arr[positive], arr[negative]);
            negative++;
        }
    }
}

int main()
{
    int a[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);
    orderingFunction(a, n);
    for(int i = 0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}