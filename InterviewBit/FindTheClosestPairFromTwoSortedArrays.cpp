vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int i = 0, j = B.size() - 1, minDiff = INT_MAX, start = -1, end = -1;
    while(i < A.size() && j >= 0) {
        if((abs(A[i] + B[j] - C) < minDiff) || 
        (abs(A[i] + B[j] - C) == minDiff && i <= start && j < end)) {
            minDiff = abs(A[i] + B[j] - C);
            start = i;
            end = j;
        }
        if(A[i] + B[j] > C)
            j--;
        else
            i++;
    }
    return { A[start], B[end] };
}

