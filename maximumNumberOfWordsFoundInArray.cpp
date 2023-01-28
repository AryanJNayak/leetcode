class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
       for(auto s:sentences)
       {
           int n = count(s.begin(),s.end(),' ')+1;
           ans = max(n,ans);
       }
        return ans;
    }
};