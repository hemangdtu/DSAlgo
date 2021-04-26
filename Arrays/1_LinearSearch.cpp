#include<iostream>
using namespace std;

int LinearSearch (int *arr, int size, int key, int &position)
{
	bool flag = false;
	for (int i = 0; i < size; ++i)
		if(arr[i]==key)
		{
			flag = true;
			position = i;
			break;
		}
	if(flag)
		return position;
	else
		return -1;
}

int main()
{
	int size;
	cin>>size;
	int arr[size];
	for(int i = 0; i<size; i++)
		cin>>arr[i];
	int key, position;
	cin>>key;
	if(LinearSearch(arr, size, key, position)!=-1)
		cout<<"Element found at index "<<position;
	else
		cout<<"Element not found!";
	return 0;
}