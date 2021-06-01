/*
Program to find the minimum (or maximum) element of an array
https://www.geeksforgeeks.org/program-find-minimum-maximum-element-array/
*/

#include <bits/stdc++.h>
using namespace std;

int minValue(int* nums, int size)
{
	return (size == 1) ? nums[0] : min(nums[0], minValue(nums + 1, size - 1));
}

int maxValue(int* nums, int size)
{
	return (size == 1) ? nums[0] : max(nums[0], maxValue(nums + 1, size - 1));
}

int main()
{
	int n;
	cin>>n;
	int nums[n];
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	cout << minValue(nums, n) << " " << maxValue(nums, n);
	return 0;
}