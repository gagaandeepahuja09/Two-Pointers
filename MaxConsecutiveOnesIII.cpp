class Solution {
public:
    // Two Pointers
    // Longest subarray with atmost K zeroes.
    int longestOnes(vector<int>& A, int k) {
        int c0 = 0, l = 0, maxLen = 0, n = A.size();
        for(int r=0; r<n; r++) {
            if(A[r] == 0)
                c0++;
            while(c0 > k) {
                if(A[l] == 0) {
                    c0--;
                }
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
