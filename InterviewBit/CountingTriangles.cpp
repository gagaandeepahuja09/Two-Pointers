#define MOD 1000000007

int Solution::nTriang(vector<int> &A) {
    int n = A.size(), cnt = 0;
    for(int k = n - 1; k >=2; k--) {
        int i = 0, j = k - 1;
        while(i < j) {
            if(A[i] + A[j] > A[k]) {
                cnt = (cnt % MOD + (j - i) % MOD) % MOD;
                j--;
            }
            else
                i++;
        }
    }
    return cnt % MOD;
}

