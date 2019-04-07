class Solution {
public:
    string removeOuterParentheses(string S) {
        int open = 0, close = 0;
        int start = 0, end = 0;
        string res;
        for(end = 0;  end < S.size(); end++) {
            if(S[end] == '(')
                open++;
            else
                close++;
            if(open == close) {
                res += (S.substr(start + 1, end - 
                                      start - 1));
                start = end + 1;
            }
        }
        return res;
    }
};
