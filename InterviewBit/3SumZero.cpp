vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> ret;
    sort(A.begin(), A.end());
    int n = A.size();
    for(int k = 0; k < n - 1; k++) {
        if(k > 0 && A[k] == A[k - 1])
            continue;
        int i = k + 1, j = n - 1;
        while(i < j) {
            if(A[i] + A[j] + A[k] < 0) {
                i++;
            }
            else if(A[i] + A[j] + A[k] > 0) {
                j--;
            }
            else {
                int sz = ret.size();
                if(sz && ret[sz - 1][0] == A[k] && ret[sz - 1][1] == A[i] &&
                ret[sz - 1][2] == A[j]);
                else
                    ret.push_back({ A[k], A[i], A[j] });
                i++;    j--;    
            }
        }
    }
    return ret;
}

