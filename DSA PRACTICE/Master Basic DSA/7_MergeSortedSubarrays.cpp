void merge(vector<int> &arr, int endIndex) {
	if (endIndex == 0) return;
	int i = 0, j = endIndex, k = 0;
	vector<int> temp;
	while(i < endIndex && j < arr.size())
	{
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i < endIndex)
		temp[k++] = arr[i++];
	while(j < arr.size())
		temp[k++] = arr[j++];
	for(int i = 0; i < arr.size(); i++)
		arr[i] = temp[i];
}