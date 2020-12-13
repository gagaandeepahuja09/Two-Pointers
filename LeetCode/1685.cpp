class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
//         1 4 6 8 10
//         1 --> sum of all right nums - (1 * (n - 1))
//         4 --> (4 * (i - 1)) - 
        int sumLeft = 0;
        for (int n : nums) {
            sumLeft += n;
        }
        int sumRight = 0;
        int lc = nums.size(), rc = 0;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            sumLeft -= nums[i];
            lc--;
            int left = sumLeft - (nums[i] * lc);
            int right = (nums[i] * (i)) - sumRight;
            sumRight += nums[i];
            // cout << left << " " << right << endl;
            ret.push_back(left + right);
        }
        return ret;
    }
};
