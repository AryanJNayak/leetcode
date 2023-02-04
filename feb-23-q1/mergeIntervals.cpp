vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int last = intervals[0][1];
        for(int i = 0; i<n; i++)
        {
            if(ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1] = max( ans.back()[1],intervals[i][1]);
            } 
            else
            {
                ans.push_back(intervals[i]);
                // last =  intervals[i][1];
            }
        }
        return ans;
    }