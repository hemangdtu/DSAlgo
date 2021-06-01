#include <bits/stdc++.h>
using namespace std;
  
unordered_map<int, int> frequency;
 
void countFrequency(int* a, int n)
{
    for (int i=0; i<n; i++)
        frequency[a[i]]++;
}

int fetchFrequency(int x)
{
    return frequency[x];
}
  
int main()
{
    int a[] = {1, 3, 2, 4, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    countFrequency(a, n);
    cout << fetchFrequency(2) << endl;
    cout << fetchFrequency(3) << endl;
    cout << fetchFrequency(5) << endl;
    return 0;
}