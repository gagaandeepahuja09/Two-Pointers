class Solution {
public:
    int numRescueBoats(vector<int>& A, int limit) {
        sort(A.begin(), A.end());
        int count = 0;
        int l = 0, h = A.size() - 1;
        while(l <= h) {
            if(A[l] + A[h] > limit) {
                h--;
            }
            else {
                l++; h--;
            }
            count++;
        }
        return count;
    }
};
