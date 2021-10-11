int getIdenticalTwinsCount(vector<int> &arr) {
	int count = 0;
	for(int i = 0; i<arr.size() - 1; i++)
		for(int j = i+1; j<arr.size(); j++)
			if(arr[i] == arr[j]) count++;
	return count;
}

/*
Observe that we want the sum of a number of possible pairs of an element of the same type. This hints at the use of hashing.

We can hash the frequency of all the numbers in the list using a hashmap and for each distinct number, we can form Nc2 = (N * (N - 1) / 2) pairs of that particular number, where N is the frequency of that number in the list.
*/

int getIdenticalTwinsCountOptimized(vector<int> &arr) {
	unordered_map<int, int> frequency;
	for(int x : arr)
		frequency[x]++;
	int count = 0;
	for(auto x : frequency)
		count += (x.second * (x.second - 1) / 2);
	return count;
}