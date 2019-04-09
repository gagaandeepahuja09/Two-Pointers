int Solution::diffPossible(vector<int> &A, int B) {
    int i = 1, j = 0;
    if(A.size() == 0 || A.size() == 1)
        return 0;
    while(i < A.size() && j < A.size()) {
        if(i == j)
            i++;
        if(A[i] - A[j] == B) {
            return 1;
        }
        else if(A[i] - A[j] < B) {
            i++;
        }
        else {
            j++;
        }
    }
    return 0;
}

