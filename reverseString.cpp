class Solution {
   void rev(vector<char>& s, int st, int e)
   {        
        if(st>e) return;
        swap(s[st],s[e]);
        rev(s,st+1,e-1);
   }
public:
   void reverseString(vector<char>& s) {
         rev(s,0,s.size()-1);
   }
 };