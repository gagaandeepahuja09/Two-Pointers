class Solution {
public:
    // Two Pointers + Sliding Window
    int maxTwoNonOverlap(vector<int>& A, int L, int M, int sz, int res = 0) {
        vector<int> left(sz + 1), right(sz + 1);
        for(int i = 0, j = sz - 1, sumL = 0, sumR = 0; i < sz; ++i, --j) {
            sumL += A[i];
            sumR += A[j];
            left[i + 1] = max(left[i], sumL);
            right[j] = max(right[j + 1], sumR);
            if(i + 1 >= L)
                sumL -= A[i + 1 - L];
            if(i + 1 >= M)
                sumR -= A[j + M - 1];
        }
        for(int i = 0; i < A.size(); i++)
            res = max(res, left[i] + right[i]);
        return res;
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(maxTwoNonOverlap(A, L, M, A.size()), maxTwoNonOverlap(A, M, L, A.size()));
    }
};
