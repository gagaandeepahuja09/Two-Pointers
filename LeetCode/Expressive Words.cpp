class Solution {
public:
    bool check(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() || j < t.size()) {
            if(j < t.size() && s[i] == t[j])
                i++, j++;
            else if(i > 1 && s[i] == s[i - 1] && s[i - 1] == s[i - 2])
                i++;
            else if(i > 0 && i < s.size() - 1 && s[i] == s[i - 1] && s[i] == s[i + 1])
                i++;
            else
                break;
        }
        return (i == s.size() && j == t.size());
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int ret = 0;
        for(auto s : words) {
            if(check(S, s))
                ret++;
        }
        return ret;
    }
};
