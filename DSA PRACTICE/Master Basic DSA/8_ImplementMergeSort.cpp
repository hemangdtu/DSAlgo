void merge(vector<int> &Arr, int start, int mid, int end) {
	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;
	while(i <= mid && j <= end)
	{
		if(Arr[i] <= Arr[j])
		{
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else
		{
			temp[k] = Arr[j];
			k += 1;
			j += 1;
		}
	}
	while(i <= mid)
	{
		temp[k] = Arr[i];
		k += 1; i += 1;
	}
	while(j <= end)
	{
		temp[k] = Arr[j];
		k += 1;
		j += 1;
	}
	for(i = start; i <= end; i += 1)
		Arr[i] = temp[i - start];
}

void mergeSortHelper(vector<int> &Arr, int start, int end) {
	if(start < end)
	{
		int mid = (start + end) / 2;
		mergeSortHelper(Arr, start, mid);
		mergeSortHelper(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

void mergeSort(vector<int> &arr) {
	mergeSortHelper(arr, 0, arr.size()-1);
}