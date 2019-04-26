vector<int> Solution::solve(vector<int> &A, int B) {
    int i = 0, j = 0, sum = 0, start = -1, end = -1;
    while(j < A.size()) {
        sum += A[j];
        j++;
        while(sum > B) {
            sum -= A[i];
            i++;
        }
        if(sum == B) {
            start = i;
            end = j;
            break;
        }
    }
    vector<int> ret;
    if(start == -1 && end == -1)
        return { -1 };
    for(int k = start; k < end; k++)
        ret.push_back(A[k]);
    return ret;
}

