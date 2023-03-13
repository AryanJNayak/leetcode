int print2largest(int arr[], int n)
{

	if (n < 2)
		return -1;

	int large = INT_MIN, seclarge = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > large)
		{
			seclarge = large;
			large = arr[i];
		}
		else if (arr[i] != large && arr[i] > seclarge)
		{
			seclarge = arr[i];
		}
	}

	if (large == INT_MIN || seclarge == INT_MIN)
	{
		return -1;
	}

	return seclarge;
}