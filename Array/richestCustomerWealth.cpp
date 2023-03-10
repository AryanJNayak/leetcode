class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max_wealth = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < accounts[i].size(); j++)
            {
                sum = sum + accounts[i][j];
            }
            max_wealth = max(max_wealth, sum);
        }
        return max_wealth;
    }
};