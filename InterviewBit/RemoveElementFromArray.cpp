int Solution::removeElement(vector<int> &A, int B) {
    int j = 0, n = A.size();
    for(int i = 0; i < n; i++) {
        if(A[i] != B) {
            A[j++] = A[i];
        }
    }
    return j;
}

