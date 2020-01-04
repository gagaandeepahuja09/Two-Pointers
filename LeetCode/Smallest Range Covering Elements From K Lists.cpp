class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int cnt = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<pair<int, int>> merge;
        for(int i = 0; i < nums.size(); i++) {
            for(auto num : nums[i])
                merge.push_back({ num, i });
        }
        sort(merge.begin(), merge.end());
        int ans = INT_MAX, start = 0;
        vector<int> ret;
        for(int i = 0; i < merge.size(); i++) {
            int val = merge[i].first, idx = merge[i].second;
            mp[idx]++;
            while(start < merge.size() && mp.size() == n) {
                int si = merge[start].second;
                bool flag = true;
                if(mp[si] == 1) {
                    flag = false;
                    break;
                }
                mp[si]--;
                start++;
            }
            int sval = merge[start].first;
            if(mp.size() == n && ans > val - sval) {
                ans = val - sval;
                ret = { sval, val };
            }
        }
        return ret;
    }
};
