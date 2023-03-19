/*
You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
*/
class Solution 
{
    public:
    bool allocate(int arr[], int n, int m, int mid)
    {
        int stu = 0;
        int count = 1;
        for(int i = 0; i<n; i++)
        {
            if(mid < arr[i]) { return false; }
            if(stu + arr[i] <= mid)  { stu += arr[i]; }
            else{ count++; stu = arr[i]; }
            if(count > m) return false;
        }
        return count <= m;
    }
    int findPages(int A[], int N, int M) 
    {
        int mini = INT_MAX;
        int  sum = 0;
        if(M>N) return -1;
        for(int i = 0; i<N; i++)
        {
            mini = min(mini,A[i]);
            sum += A[i];
        }
        
        int low = 1, high = sum, ans = -1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(allocate(A,N,M,mid) == true) { ans = mid; high = mid - 1; }
            else { low = mid + 1; }
        }
        return ans;
    }
};