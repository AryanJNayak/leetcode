class Solution {
private:
   char lower(char ch)
     {
          if(ch >= 'a' && ch <= 'z') { return ch; }
          else { 
            char temp = (ch - 'A' + 'a');
             return temp;
             }
    }
   bool valid(char ch)
     {
         if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch<='9'&&ch>='0'))
           {
             return 1;
           }
        return 0;
      }

public:
    bool isPalindrome(string s) {
        int st = 0, e = s.size()-1;
         while(st<e)
           {        
             if(valid(s[st])) 
               {
                if(valid(s[e]))
                   {
                     if(lower(s[st]) == lower(s[e])) { st++,e--;  }
                     else{ return 0; }
                } 
                else{ e--; }          
             }
              else{st++;}
       }
    return 1;
    }
};
