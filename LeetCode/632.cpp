class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ret;
        int n = nums.size();
        vector<vector<int>> mergedList;
        for (int i = 0; i < n; i++) {
            for (int num: nums[i]) {
                mergedList.push_back({ num, i });
            }
        }
        sort(mergedList.begin(), mergedList.end());
        unordered_map<int, int> mp;
        int rangeMin = INT_MAX;
        int j = 0;
        for (int i = 0; i < mergedList.size(); i++) {
            int endIdx = mergedList[i][1], endVal = mergedList[i][0];
            mp[endIdx]++;
            while(j < mergedList.size() && mp.size() == n) {
                int startIdx = mergedList[j][1];
                if (mp[startIdx] == 1) {
                    break;
                }
                mp[startIdx]--;
                j++;
            }
            int startVal = mergedList[j][0];
            if (mp.size() == n && endVal - startVal < rangeMin) {
                rangeMin = endVal - startVal;
                ret = { startVal, endVal };
            }
        }
        return ret;
    }
};
