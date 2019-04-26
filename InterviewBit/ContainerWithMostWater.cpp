int Solution::maxArea(vector<int> &A) {
    int i = 0, j = A.size() - 1;
    int maxContainer = 0;
    while(i < j) {
        maxContainer = max(maxContainer, min(A[i], A[j]) * (j - i));
        if(A[i] < A[j])
            i++;
        else
            j--;
    }
    return maxContainer;
}

