// Nearest Greater to Right

#include <bits/stdc++.h>
using namespace std;

void bruteforce(int* arr, int size)
{
	vector<int> result(size);
	for(int i = 0; i<size; i++)
	{
		int reference = arr[i];
		int j = i + 1;
		while(j < size && arr[j] <= reference)
			j++;
		if(j == size)
			cout << "-1";
		else
			cout << arr[j] << " ";
	}
}

vector<int> optimization(int* arr, int size)
{
	vector<int> result;
	stack<int> numberBucket;
	for(int i = size - 1; i>=0; i--)
	{
		if(numberBucket.empty())
			result.push_back(-1);
		else
		{
			while(numberBucket.top() <= arr[i] && !numberBucket.empty())
				numberBucket.pop();
			
			if(numberBucket.empty())
				result.push_back(-1);
			else
				result.push_back(numberBucket.top());
		}
		numberBucket.push(arr[i]);
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
		cin >> arr[i];

	bruteforce(arr, n);
	cout << endl;

	vector<int> result;
	result = optimization(arr, n);
	for(auto& i : result)
		cout << i << " ";
	
	return 0;
}