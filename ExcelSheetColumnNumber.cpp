class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for(auto c:columnTitle)
        {
            int d = c-'A'+1;
            sum = sum * 26 +d;
        }        
        return sum;
    }
};