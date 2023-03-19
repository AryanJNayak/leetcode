/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/
class Solution {
public:
    double power(double x, long long n) {
        //power of x^0 is always 1
        if(n == 0) {return 1.0;}

        if(n&1) {
            //odd power
            return x*power(x,n-1);
        }
        
        //even power
        return power(x*x,n/2);
    }
    double myPow(double x, int n) {
        //store sign 
        bool sign = false;;
        if(n < 0) {sign = true;}
        
        //convert to positive int if n is < 0
        long long N = abs(n);
        double ans = power(x,N);

        //if sign is -ve
        if(sign) {
            return 1/ans;
        }

        //sign is +ve
        return ans;
    }
};