int largest(vector<int> &arr, int n)
    {
        int maxi = INT_MIN;
        for(auto it:arr)
        {
            if(maxi < it) maxi = it;
        }
        return maxi;
    }