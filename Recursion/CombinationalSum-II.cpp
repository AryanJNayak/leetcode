/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/
class Solution {
  public:
    void func(int i, vector<int>& arr, int n,vector<int>& a, vector<vector<int>>&ans,int sum){
        //if we achieve target/sum
        if(sum == 0) {
            //we have got one of the combination
            ans.push_back(a);
            return;
        }
        
        //starting from current element to n
        for(int idx = i; idx<n; idx++) {
            
            //ignore duplicate element
            if(idx > i && arr[idx] == arr[idx-1]) continue;
            
            //ignore case if sbtracting (element - sum) gives -ve answer
            if(arr[idx]>sum) {break;}
            
            //function call for the next all the array element
            a.push_back(arr[idx]);
            func(idx+1,arr,n,a,ans,sum-arr[idx]);
            a.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int> &arr, int sum) {
        vector<vector<int>> ans;
        vector<int>a;
        sort(arr.begin(),arr.end());
        func(0, arr, arr.size(),a, ans, sum);
        return ans;
    }
};