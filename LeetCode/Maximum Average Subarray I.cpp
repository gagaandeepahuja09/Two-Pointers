class Solution {
public:
    double findMaxAverage(vector<int>& A, int k) {
        int maxSum = INT_MIN, currSum = 0;
        for(int i = 0; i < A.size(); i++) {
            if(i < k)
                currSum += A[i];
            else {
                maxSum = max(maxSum, currSum);
                currSum +=  A[i] - A[i - k];
            }
        }
        maxSum = max(maxSum, currSum);
        return (double)(maxSum) / (double)(k);
    }
};
