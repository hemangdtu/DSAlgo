/*
Find the Missing Number
https://www.geeksforgeeks.org/find-the-missing-number/
*/

#include<bits/stdc++.h>
using namespace std;

int missingNumber(int* arr, int n)
{
	int x1 = arr[0];
    int x2 = 1;

    for (int i = 1; i < n; i++)
    {
    	x1 = x1 ^ arr[i];
    	if(i > 1)
    		x2 = x2 ^ i;
    }
    
    x2 = x2 ^ n;
    x2 = x2 ^ n+1;

    return (x1 ^ x2);
}

int main()
{
	int nums[] = {1, 2, 4, 6, 3, 7, 8};
	int n = sizeof(nums) / sizeof(nums[0]);

	cout << missingNumber(nums, n);

	return 0;
}
