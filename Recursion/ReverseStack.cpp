/*
You are given a stack St. You have to reverse the stack using recursion.

Example 1:
Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
*/
class Solution{
public:
    void btm(int x, stack<int>& s) {
        if(s.empty()) {
            s.push(x);
            return;
        }
        int y = s.top();
        s.pop();
        btm(x,s);
        s.push(y);
    }
    void Reverse(stack<int> &st) {
        if(st.empty()) {
            return;
        }
        
        int x = st.top();
        st.pop();
        Reverse(st);
        btm(x,st);
    }
};