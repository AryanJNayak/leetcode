class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans(0);
        int x = *max_element(candies.begin(),candies.end());
        
        for(int i = 0; i<candies.size(); i++)
        {
            if( candies[i] +  extraCandies >= x) {ans.push_back(1);}
            else { ans.push_back(0);}
        }
        
        return ans;
    }
};