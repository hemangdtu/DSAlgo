vector<int> getEvenDigitNumbers(vector<int> &arr) {
	vector<int> result;
	for(int val : arr)
	{
		string num = to_string(val);
		if(num.length() % 2 == 0)
			result.push_back(val);
	}
	return result;
}