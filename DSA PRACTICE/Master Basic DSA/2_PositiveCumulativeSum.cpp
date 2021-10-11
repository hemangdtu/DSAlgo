vector<int> getPositiveCumulativeSum(vector<int> &arr) {
	vector<int> result;
	if(arr[0] > 0) result.push_back(arr[0]);
	for(int i = 1; i< arr.size(); i++)
	{
		arr[i] += arr[i-1];
		if(arr[i] > 0)
			result.push_back(arr[i]);
	}
	return result;
}