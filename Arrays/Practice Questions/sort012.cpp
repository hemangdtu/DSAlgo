#include <bits/stdc++.h>
using namespace std;

void sort012(int* a, int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
    while (mid <= hi)
    {
        switch (a[mid])
        {
            case 0:
            swap(a[lo++], a[mid++]);
            break;

            case 1:
            mid++;
            break;

            case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}

int main()
{
    int a[] = {1, 0, 2, 0, 1, 2};
    int n = sizeof(a)/sizeof(a[0]);
    sort012(a, n);
    return 0;
}