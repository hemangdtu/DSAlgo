/*
Write a program to reverse an array or string
https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int* nums, int start, int end)
{
	if(start >= end)
		return;

	int temp = nums[start];
	nums[start] = nums[end];
	nums[end] = temp;

	reverseArray(nums, start + 1, end - 1);
}

int main()
{
	int n;
	cin>>n;
	int nums[n];
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	reverseArray(nums, 0, n-1);

	for(int i = 0; i < n; i++)
		cout << nums[i] << " ";
	return 0;
}