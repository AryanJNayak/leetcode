/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/
void sortS(stack<int>& st) {
    if(st.empty()) { return; }
    
    int x = st.top();
    st.pop();
    sortS(st);
    
    if(st.empty()) {
        st.push(x);
    } else {
        stack<int>s;
        while(!st.empty() && st.top() > x ) {
            s.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!s.empty()) {
            st.push(s.top());
            s.pop();
        }
    }
}
void SortedStack :: sort()
{
   sortS(s);
}