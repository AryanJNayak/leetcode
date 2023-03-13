long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    int i, j, k;
    i = left;
    j = mid;
    k = left;
    long long int cnt = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += mid - i;
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return cnt;
}

long long int _merge(long long arr[], long long temp[], long long left, long long right)
{
    int mid;
    long long int cnt = 0;
    if (left < right)
    {
        mid = (left + right) / 2;
        cnt += _merge(arr, temp, left, mid);
        cnt += _merge(arr, temp, mid + 1, right);

        cnt += merge(arr, temp, left, mid + 1, right);
    }
    return cnt;
}

long long int inversionCount(long long arr[], long long N)
{
    long long temp[N] = {0};
    return _merge(arr, temp, (long long)0, N - 1);
}