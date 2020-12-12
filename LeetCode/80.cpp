class Solution {
public:    
    int removeDuplicates(vector<int>& A) {
        int i = 1, j = 1, k = 2, n = A.size(), cnt = 1;
        if (n <= k)
            return n;
        for(j = 1; j < n; j++) {
            if (A[j] != A[j - 1]) {
                A[i++] = A[j];
                cnt = 1;
            }
            else {
                if (cnt < k) {
                    A[i++] = A[j];
                    cnt++;
                }
            }
        }
        return i;
    }
};
