class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        vector<int> cnt(26, 0), c2(26, 0);
        for(int i = 0; i < n; i++) {
            cnt[p[i] - 'a']++;
        }
        vector<int> ret;
        for(int i = 0; i < s.size(); i++) {
            c2[s[i] - 'a']++;
            if(i >= n)
                c2[s[i - n] - 'a']--;
            if(i >= n - 1 && c2 == cnt)
                ret.push_back(i - n + 1);
        }
        return ret;
    }
};
