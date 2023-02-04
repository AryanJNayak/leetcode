 int *findTwoElement(int *arr, int n) {
        int missing = -1, reapet = -1;
        long long sum = (n*(n+1))/2;
        long long sumseq = ( (n * (n+1)) * ( (2*n) +1) )/2;
        
        for(int i = 0; i<n; i++)
        {
            sum -= arr[i];
            sumseq -= arr[i]*arr[i];
        }
        
        missing = (sum + (sumseq/sum)) /2;
        reapet = sum - missing;
        
        int *ans = new int[2];
        
        ans[0] = reapet;
        ans[1] = missing;
        return ans;
    }