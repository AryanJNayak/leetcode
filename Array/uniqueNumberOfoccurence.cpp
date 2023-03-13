class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            while (i + 1 < n && arr[i] == arr[i + 1])
            {
                cnt++;
                i++;
            }
            cnt++;
            ans.push_back(cnt);
        }
        sort(ans.begin(), ans.end());
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] == ans[i - 1])
                return 0;
        }
        return 1;
    }
};