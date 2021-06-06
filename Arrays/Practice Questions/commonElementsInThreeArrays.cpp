/*
Find common elements in three sorted arrays
https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(int* a1, int* a2, int* a3, int n1, int n2, int n3)
{
	vector<int> result;
	unordered_map<int, int> m1, m2, m3;
	for(int i = 0; i<n1; i++)
		m1[a1[i]]++;
	for(int i = 0; i<n2; i++)
		m2[a2[i]]++;
	for(int i = 0; i<n3; i++)
		m3[a3[i]]++;
	for(int i = 0; i<n1; i++)
	{
		if(m1[a1[i]] > 0 && m2[a1[i]] > 0 && m3[a1[i]] > 0)
			result.push_back(a1[i]);
		m1[a1[i]] = 0;
	}
	return result;
}

int main()
{
	int ar1[] = { 1, 5, 10, 20, 40, 80, 80 };
	int ar2[] = { 6, 7, 20, 80, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	vector<int> result = commonElements(ar1, ar2, ar3, n1, n2, n3);

	for(auto i : result)
		cout << i << " ";

	return 0;
}
