class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums1[i]]++;
        }
        for (int j = 0; j < m; j++)
        {
            if (mp[nums2[j]])
            {
                ans.push_back(nums2[j]);
                mp[nums2[j]]--;
            }
        }
        return ans;
    }
};