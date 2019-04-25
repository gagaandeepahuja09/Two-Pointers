int Solution::solve(vector<int> &A, int B) {
    int cnt = 0;
    int i = 0, j = A.size() - 1;
    while(i < j) {
        if(A[i] + A[j] == B) {
            int c1 = 1, c2 = 1;
            while(i < A.size() - 1 && A[i] == A[i + 1])
                i++;
            while(j > 0 && A[j] == A[j - 1])
                j--;
            if(A[i] != A[j]) 
                cnt += (c1 * c2);
            else 
                cnt += c1;
            i++;
            j--;
        }
        else if(A[i] + A[j] > B)
            j--;
        else if(A[i] + A[j] && i == j - 1) {
            i++;
            j++;
        }
        else
            i++;
    }
    return cnt;
}

