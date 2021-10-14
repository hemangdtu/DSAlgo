vector<int> getSquareSortedArray(vector<int> &arr) {
    int n = arr.size();
	for(int i = 0; i < n; i++)
		arr[i] = arr[i] * arr[i];
	sort(arr.begin(), arr.end());
	return arr;
}