int partition (vector<int> &a, int start, int end) {
	int pivot = a[end], i = (start - 1);
	for(int j = start; j <= end - 1; j++)
	{
		if(a[j] < pivot)
		{
			i++;
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	int t = a[i+1];
	a[i+1] = a[end];
	a[end] = t;
	return (i + 1);  
}

void quick(vector<int> &a, int start, int end) {
	if (start < end)
	{
		int p = partition(a, start, end);
		quick(a, start, p - 1);
		quick(a, p + 1, end);
	}
}

void quickSort(vector<int> &arr) {
	quick(arr, 0, arr.size() - 1);
}