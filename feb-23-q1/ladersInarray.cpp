vector<int> leaders(int a[], int n){
        vector<int> ans;
        int mini = a[n-1];
        ans.push_back(mini);
        for(int i =n-2; i>=0; i--)
        {
            if(a[i] >= mini)
            {
                ans.push_back(a[i]);
                mini = a[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }