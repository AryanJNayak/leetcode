int maxLen(vector<int>&A, int n)
    {  
        if(n == 0) return -1;
        if(n == 1 && A[0] == 0) return 1;
        unordered_map<int,int>mp;
        int sum = 0, len = 0;
        for(int i =0; i<n; i++)
        {
            sum += A[i];
            if(sum == 0) { len  = i+1; }
            else 
            {
                if( mp.find(sum) != mp.end() )
                {
                    len = max(len,i - mp[sum]);
                } else
                {
                    mp[sum] = i;
                }
            }
        }
        return len;
    }