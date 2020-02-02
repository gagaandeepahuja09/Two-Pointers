class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> mp;
        int j = 0, ans = 0;
        for(int i = 0; i < tree.size(); i++) {
            mp[tree[i]]++;
            while(j < tree.size() && mp.size() > 2) {
                if(--mp[tree[j]] == 0)
                    mp.erase(tree[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
