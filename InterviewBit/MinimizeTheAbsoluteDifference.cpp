int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0, ans = INT_MAX;
    int l = A.size(), m = B.size(), n = C.size();
    while(i < l && j < m && k < n) {
        int mn = min(A[i], min(B[j], C[k]));
        int mx = max(A[i], max(B[j], C[k]));
        ans = min(ans, mx - mn);
        if(mn == A[i])
            i++;
        else if(mn == B[j])
            j++;
        else if(mn == C[k])
            k++;
    }
    return ans;
}

