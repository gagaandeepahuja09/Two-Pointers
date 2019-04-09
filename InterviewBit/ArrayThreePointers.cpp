int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int l = A.size(), m = B.size(), n = C.size();
    int ans = INT_MAX;
    while(i < l && j < m && k < n) {
        int mn = min(A[i], min(B[j], C[k]));
        int curr = max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), 
        abs(A[i] - C[k])));
        ans = min(curr, ans);
        if(A[i] == mn)
            i++;
        else if(B[j] == mn)
            j++;
        else
            k++;
    }
    return ans;
}

