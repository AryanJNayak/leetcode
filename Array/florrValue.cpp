int findFloor(vector<long long> v, long long n, long long x)
{
    int florr = -1;
    int si = 0, ei = n - 1;
    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;
        if (v[mid] == x)
            return mid;
        if (v[mid] < x)
        {
            florr = mid;
            si = mid + 1;
        }
        else if (v[mid] > x)
            ei = mid - 1;
    }
    return florr;
}