class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == t[j])
                j++;
        }
        return (j == t.size());
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for(int i = 0; i < d.size(); i++) {
            if(isSubsequence(s, d[i])) {
                if(ans == "" || d[i].size() > ans.size())   
                    ans = d[i];
                else if(d[i].size() == ans.size())   
                    ans = min(ans, d[i]);
            }
        }
        return ans;
    }
};
