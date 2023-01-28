class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       int c=0;
        unordered_set<char>s;
       
           
        for(auto i:jewels)
             s.insert(i);
        
         for(auto j:stones)
                if(s.find(j)!=s.end())
                c++;
        
        return c;
    }
};