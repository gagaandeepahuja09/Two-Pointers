class Solution {
public:
    int f(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size(), i = 0, j = 0, cnt = 0;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] % 2)
                cnt++;
            while(j < n && cnt > k) {
                if(nums[j] % 2)
                    cnt--;
                j++;
            }
            if(cnt == k) {
                ans += (j);
            }
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k - 1) - f(nums, k);
    }
};
