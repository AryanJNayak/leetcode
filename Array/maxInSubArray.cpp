long long pairWithMaxSum(long long arr[], long long N)
{
    long ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if ((arr[i] + arr[i + 1]) > ans)
        {
            ans = arr[i] + arr[i + 1];
        }
    }
    return ans;
}