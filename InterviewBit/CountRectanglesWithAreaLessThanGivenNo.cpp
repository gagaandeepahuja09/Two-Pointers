/*
Given a sorted array of distinct integers A and an integer B, find and return how many 
rectangleswith distinct configurations can be created using elements of this array as
length and breadth whose area is lesser than B. 
*/

#define MOD 1000000007

int Solution::solve(vector<int> &A, int B) {
    int i = 0, j = A.size() - 1, cnt = 0;
    while(i <= j) {
        if(A[i] * A[j] < B) {
            cnt = cnt % MOD + (2 * (j - i + 1) - 1) % MOD;
            i++;
        }
        else
            j--;
    }
    return cnt;
}

