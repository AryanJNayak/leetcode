class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        string x;
        int ans = 0;
        for(int i = 0; i<operations.size(); i++)
        {
            if(operations[i] == "X++") { ans++; }
            else if(operations[i] == "X--") { ans--; }
            else if(operations[i] == "++X") { ++ans; }
            else if(operations[i] == "--X") { --ans; }
        }
        return ans;
    }
};
