void Solution::sortColors(vector<int> &A) {
    int i = 0, j = A.size() - 1;
    for(int k = 0; k <= j; k++) {
        if(A[k] == 0) {
            swap(A[i++], A[k]);
        }
        if(A[k] == 2) {
            swap(A[j--], A[k--]);
        }
    }
}

