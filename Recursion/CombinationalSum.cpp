/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
    2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
    7 is a candidate, and 7 = 7.
    These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []
*/

class Solution {
public:
    void func(int ind, vector<int>& num, int target, int n, vector<vector<int>>&ans,
    vector<int>& out) {
        //if sum/target is achieved
        if(target == 0) {

            //insert into ans
            ans.push_back(out);
            return;
        }

        //return if 'ind' reaches end
        //target-currentElement will be less than 0 no need to check grater element as 'num' is sorted
        if(ind == n || target-num[ind] < 0) {
            return;
        }

        //includeing currentElement
        out.push_back(num[ind]);
        func(ind,num,target-num[ind],n,ans,out);
        out.pop_back();//restore out

        //excludeing currentElement
        func(ind+1,num,target,n,ans,out);
    }
    vector<vector<int>> combinationSum(vector<int>& num, int target) {
        vector<vector<int>> ans;
        vector<int>out;
        sort(num.begin(), num.end());
        func(0,num,target,num.size(),ans,out);
        return ans;
    }
};