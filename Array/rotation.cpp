int findKRotation(int arr[], int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (arr[e] > arr[mid])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return e;
}