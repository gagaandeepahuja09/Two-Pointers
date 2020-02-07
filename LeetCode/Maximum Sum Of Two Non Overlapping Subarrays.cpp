class Solution {
public:
    int maxOverlap(vector<int>& A, int l, int m) {
        int n = A.size();
        vector<int> leftMax(n + 1), rightMax(n + 1);
        int ans = 0, currLeft = 0, currRight = 0, i = 0, j = n - 1;
        while(i < n) {
            currLeft += A[i];   currRight += A[j];
            if(i - l >= 0) {
                currLeft -= A[i - l];
            }
            if(j + m <= A.size() - 1) {
                currRight -= A[j + m];
            }
            leftMax[i + 1] = max(leftMax[i], currLeft);
            rightMax[j] = max(rightMax[j + 1], currRight);
            i++;    j--;
        }
        for(int i = 0; i < n; i++)
            ans = max(ans, leftMax[i] + rightMax[i]);
        return ans;
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(maxOverlap(A, L, M), maxOverlap(A, M, L));
    }
};
