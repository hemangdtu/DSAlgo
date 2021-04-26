#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	sort(arr, arr+n);
	int key, middle, first = 0, last = n-1;
	bool flag = false;
	cin>>key;
	for(int i = 0; i<n; i++)
	{
		middle = (first + last)/2;
		if(arr[middle] == key)
		{
			flag = true;
			break;
		}
		else if(arr[middle]>key)
			last = middle;
		else
			first = middle;
	}
	if(flag)
		cout<<"Element Found!";
	else
		cout<<"No Match Found!";
	return 0;
}