class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int len = s.size();
        unordered_map<char, int> mp;
        for(char ch : s)
            mp[ch]++;
        int i = 0;
        for(int j = 0; j < n; j++) {
            mp[s[j]]--;
            while(i < n && mp['Q'] <= n / 4 && mp['W'] <= n / 4 && mp['E'] <= n / 4 && mp['R'] <= n / 4) {
                len = min(len, j - i + 1);
                mp[s[i++]]++;
            }
        }
        return len;
    }
};
