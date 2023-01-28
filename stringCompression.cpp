class Solution {
public:
    int compress(vector<char>& chars) {
        int x  = 0,i = 0;
        int n = chars.size();
        while(i<n)
        {
            int j  = i+1;
            while(j<n && chars[i] == chars[j])
                {
                  j++;
                 }
            chars[x++] = chars[i];
            int k = j-i;
             if(k>1){
                string cnt = to_string(k);
                 for(char ch:cnt) 
                 { chars[x++] = ch; }
            }
            i = j;
        }
        return x;
    }
};