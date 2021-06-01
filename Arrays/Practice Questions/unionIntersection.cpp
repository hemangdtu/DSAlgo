#include <bits/stdc++.h>
using namespace std;

void intersectionPrint(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}

void unionPrint(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
 
        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";
 
        else
        {
            cout << arr2[j++] << " ";
            i++;
        }
    }

    while (i < m)
        cout << arr1[i++] << " ";
 
    while (j < n)
        cout << arr2[j++] << " ";
}

int main()
{
    int a[] = {1, 2, 4, 5, 6};
    int n = sizeof(a)/sizeof(a[0]);
    int b[] = {2, 3, 5, 7};
    int m = sizeof(b)/sizeof(b[0]);
    intersectionPrint(a, b, n, m);
    cout<<"\n";
    unionPrint(a, b, n, m);
    return 0;
}