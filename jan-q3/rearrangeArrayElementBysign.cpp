class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>neg;
	    vector<int>pos;
	    
	    for(auto it:nums)
	    {
	        if(it < 0) neg.push_back(it);	        
	        else pos.push_back(it);
	    }
	    
	    auto it = pos.begin();
	    auto it1 = neg.begin();
	    int i = 0;
        nums.clear();
	    while(it != pos.end() && it1 != neg.end())
	    {
	        nums.push_back(*(it));
	        it++;
	        nums.push_back(*(it1));
	        it1++;
	        i+=2;
	    }
	    
	    while(it != pos.end())
	    {
	        nums.push_back(*(it));
	        it++;
	    }
	    
	    while(it1 != neg.end())
	    {
	        nums.push_back(*(it1));
	        it1++;
	    }
        return nums;
    }
};