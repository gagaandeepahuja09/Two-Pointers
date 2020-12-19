class Solution {
public:
    int f(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size(), j = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1)
                cnt++;
            while (j < n && cnt > k) {
                if (nums[j] % 2 == 1)
                    cnt--;
                j++;
            }
            ans += (j + 1);
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k - 1) - f(nums, k);
    }
};
