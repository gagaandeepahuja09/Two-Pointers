class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for(string t : d) {
            int i = 0, j = 0;
            for(j = 0; j < s.size(); j++) {
                if(s[j] == t[i])
                    i++;
            }
            if(i == t.size() && (t.size() > ans.size() || (t.size() == ans.size() && t < ans))) {
                ans = t;
            }
        }
        return ans;
    }
};
