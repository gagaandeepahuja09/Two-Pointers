vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size(), i = 0, j = 0;
    vector<int> ret;
    while(i < n && j < m) {
        if(A[i] < B[j]) {
            i++;
        }
        else if(B[j] < A[i]) {
            j++;
        }
        else {
            ret.push_back(A[i]);
            i++;    j++;
        }
    }
    return ret;
}

