class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int j = 0;
        vector<int> c(3, 0);
        for(int i = 0; i < s.size(); i++) {
            c[s[i] - 'a']++;
            while(j < i && c[0] >= 1 && c[1] >= 1 && c[2] >= 1) {
                (c[s[j++] - 'a']--);
            }
            ans += j;
        }
        return ans;
    }
};
