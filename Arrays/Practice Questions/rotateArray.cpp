/*
Program to rotate an array by k places.
https://www.geeksforgeeks.org/print-array-after-it-is-right-rotated-k-times/
*/

#include<bits/stdc++.h>
using namespace std;

void rotateArray(int* arr, int size)
{
	int temp = arr[size - 1];
	for(int i = size - 1; i > 0; i--)
		arr[i] = arr[i-1];
	arr[0] = temp;
}

int main()
{
	int nums[] = {3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3};
	int n = sizeof(nums) / sizeof(nums[0]);

	int k;
	cin >> k;
	k %= n;

	while(k--)
		rotateArray(nums, n);

	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";

	return 0;
}
