class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        int n = pattern.size();
        for(int i = 0; i < queries.size(); i++) {
            string s = queries[i];
            bool ans = true;
            int k = 0;
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == pattern[k])
                    k++;
                else if(s[j] >= 'A' && s[j] <= 'Z')
                    ans = false;
            }
            if(k != n)
                ans = false;
            res.push_back(ans);
        }
        return res;
    }
};
