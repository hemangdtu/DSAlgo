/*
Check if a key is present in every segment of size k in an array
https://www.geeksforgeeks.org/check-if-a-key-is-present-in-every-segment-of-size-k-in-an-array/
*/

#include<bits/stdc++.h>
using namespace std; 

bool segmentCheck(int* arr, int k, int x, int size, int index)
{
	int count = 0;
	if(index + k == size)
	{
		for(int i = 0; i <k; i++)
			if(arr[i] == x)
				count++;
		return count != 0;
	}
	bool check = segmentCheck(arr + k, k, x, size, index + k);
	for(int i = 0; i <k; i++)
		if(arr[i] == x)
			count++;
	return (count != 0) && check;
}

int main()
{
	int nums[] = {3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3};
	int n = sizeof(nums) / sizeof(nums[0]);
	cout<<segmentCheck(nums, 3, 3, n, 0);
	return 0;
}