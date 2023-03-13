/*
given an banned[] and 'n' and 'maxSum'. choose some number of integers following the below rules:
-> chosen integers are distinct and in the range of [1, n].
-> chosen integers not be in the banned[].
-> sum of chosen integers not exceed maxSum.

You have to Return :- the maximum number of integers you can choose following the mentioned rules.


Example 1:
Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: [2,4]

Example 2:
Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0

Example 3:
Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: [1, 2, 3, 4, 5, 6, 7].

*/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
       //the maximum length of banned is 10^4
       //map banned element to index of ans: ans[banned[.]] = 1
       int ans[10001] = {1}; //mark all banned index as one
       for(int j = 0; j<banned.size(); j++)
       {
            ans[banned[j]] = 1;       
       }
        
       int currentsum = 0;//get current sum to check our sum not exeend maxSum
       int cnt = 0;//return count of elemnt in currentSum
       for(int i = 1; i<=n; i++)
       {
           //starting i from 1 to n 
           // IF i not banned 
           if(ans[i] == 0) 
           {
               //and if adding i to currentSum, currentSum exceeds return cnt
               // else add i  to currentSum
               if(currentsum + i > maxSum) { return cnt; }
               currentsum = currentsum + i; 
               cnt++; 
           }
       }
       return cnt;
    }
};