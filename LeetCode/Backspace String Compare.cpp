class Solution {
public:
    /* string change(string S, stack<int> stk) {
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '#') {
                if(stk.size())
                    stk.pop();
            }
            else {
                stk.push(S[i]);
            }
        }    
        string s;
        while(!stk.empty()) {
            s += stk.top();
            stk.pop();
        }
        return s; 
    } */
    
    int change(string &S) {
        int idx = 0, n = S.size();
        for(int i = 0; i < n; i++) {
            if(S[i] == '#') {
                idx = max(idx - 1, 0);
            }
            else {
                S[idx] = S[i];
                idx++;
            }
        }
        return idx;
    }
    
    bool backspaceCompare(string S, string T) {
        // stack<int> stk;
        int i = change(S), j = change(T);
        if(i != j) {
            return false;
        }
        for(int k = 0; k < i; k++) {
            // cout << S[k] << " " << T[k] << endl;
            if(S[k] != T[k]) {
                return false;
            }
        }
        return true;
    }
};
