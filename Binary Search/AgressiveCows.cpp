/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
*/

class Solution {
public:
    bool possible(vector<int>& arr, int k, int mid)
    {
        int cow = 1, n = arr.size();
        int c1 = arr[0];
        for(int i = 1;i<n; i++)
        {
            if(arr[i]-c1 >= mid) { cow++; c1 = arr[i]; }
            if(cow == k) { return true;}
        }
        return false;
    }
    int solve(int n, int k, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int low = 1, high = arr[n-1]-arr[0], ans = 0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(possible(arr,k,mid) == true) { low = mid + 1; }
            else { high = mid - 1; }
        }
        return high;
    }
};