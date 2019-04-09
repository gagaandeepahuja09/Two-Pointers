int Solution::threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    int ans = INT_MAX;
    int minDiff = INT_MAX;
    sort(A.begin(), A.end());
    for(int k = 1; k < n - 1; k++) {
        int i = 0, j = n - 1;
        while(i < j) {
            int sum = A[i] + A[j] + A[k];
            if(minDiff > abs(B - sum)) {
                ans = sum;
                minDiff = abs(B - sum);
            }
            if(sum < B) {
                i++;
                if(i == k) {
                    i++;
                }
            }
            else if(sum > B) {
                j--;
                if(j == k)
                    j--;
            }
            else
                return B;
        }
    }
    return ans;
}

