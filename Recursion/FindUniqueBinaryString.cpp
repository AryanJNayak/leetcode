/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:
Input: nums = ["01","10"]
Output: "11"

Example 2:
Input: nums = ["00","01"]
Output: "11"

Example 3:
Input: nums = ["111","011","001"]
Output: "101"
*/


//approach 1
class Solution {
public:
    string a = "";
    bool func(int i, int n, string s, set<string>& ds) {
        //i reaches n
        if(i == n) {
            //search ds contain s or not
            if(ds.find(s) == ds.end()) {
                a = s;
                return true;
            }
            ds.insert(s);
            return false;
        }
        
        //insert '1'
        s[i] = '1';
        if(func(i+1,n,s,ds)){
            return true;
        }
        s[i] = '0';//Back-Track

        //not insert anything
        func(i+1,n,s,ds);
        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        //get length of string
        int n = nums[0].length();
        string s(n,'0');
        
        //insert into stack
        set<string>ds;
        for(auto num:nums ) { st.insert(num); }
        
        func(0,n,s,ds);
        return a;
    }
};


//approach 2
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";

        for(int i=0;i<nums.size();i++){

            if(nums[i][i] == '1')
            ans += '0';
            else 
            ans += '1';
        }

        return ans;
    }
};