/*
Given a sorted array Arr[](0-index based) consisting of N distinct integers and an integer k, the task is to find the index of k, if its present in the array Arr[]. Otherwise, find the index where k must be inserted to keep the array sorted.


Example 1:
Input:
N = 4
Arr = {1, 3, 5, 6}
k = 5
Output: 2
*/
class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        if( k == Arr[N-1]) { return N-1; }
        if( k > Arr[N-1]) { return N; }
        if( k <= Arr[0]) { return 0; }
        int s = 0, e = N-1;
        int pos = -1;
        while(s <= e)
        {
            int mid = ((s + e) / 2);
            if(Arr[mid] == k) { return mid; }
            if(Arr[mid] < k) { s = mid+1; }
            else { e = mid - 1;}
        }
        
        return s;
    }
};