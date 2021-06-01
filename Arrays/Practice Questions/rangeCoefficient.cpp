#include <bits/stdc++.h>
using namespace std;

int getMin(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        res = min(res, arr[i]);
    return res;
}
 
int getMax(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        res = max(res, arr[i]);
    return res;
}

pair<int , float> findRangeAndCoefficient(int arr[], int n)
{
    int max = getMax(arr, n);
    int min = getMin(arr, n);
    int range = max - min;
    float coeffOfRange = range / (float)(max + min);
    pair<int , float> result = make_pair(range, coeffOfRange);
    return result;
}

int main()
{
    int a[] = {15, 16, 10, 9, 6, 7, 17};
    int n = sizeof(a)/sizeof(a[0]);
    pair<int, float> result = findRangeAndCoefficient(a, n);
    cout<<result.first<<" "<<result.second;
    return 0;
}