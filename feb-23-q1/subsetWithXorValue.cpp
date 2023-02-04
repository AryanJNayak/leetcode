 int subsetXOR(vector<int> arr, int N, int K) {
        
        int xorr = 0;
        int cnt = 0;
        map<int,int>mp;
        
        for( int it:arr )
        {
            xorr = xorr ^ it;
            
            if( xorr== K ) { cnt++; }
            
            if(mp.find(xorr^K) != mp.end()) 
            {
                cnt += mp[xorr^K];
            }
            
            mp[xorr]+=1;
        }
        
        return cnt;
    }