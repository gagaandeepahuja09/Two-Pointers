class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ret = 0, up = 0, down = 0;
        for(int i = 1; i < A.size(); i++) {
            if(down && A[i - 1] < A[i] || A[i - 1] == A[i]) {
                up = down = 0;
            }
            up += (A[i - 1] < A[i]);
            down += (A[i - 1] > A[i]);
            if(up && down) {
                ret = max(ret, up + down + 1);
            }
        }
        return ret;
    }
};
