class Solution {
public:
    string reverseParentheses(string s) {
        string temp;
        stack<int> stk;
        string ret;
        int n = s.size();
        vector<int> pair(n, -1);
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                int t = stk.top();  stk.pop();
                pair[i] = t; pair[t] = i;
            }
        }
        int dir = 1;
        for(int i = 0; i < n; i += dir) {
            if(s[i] == '(' || s[i] == ')') {
                dir = -dir;
                i = pair[i];
            }
            else {
                ret += s[i];
            }
        }
        return ret;
    }
};
