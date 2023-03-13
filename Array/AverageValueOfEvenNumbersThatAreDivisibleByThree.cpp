class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] % 3 == 0) && !(nums[i] & 1))
            {
                sum += nums[i];
                cnt++;
            }
        }
        return cnt == 0 ? sum : sum / cnt;
    }
};