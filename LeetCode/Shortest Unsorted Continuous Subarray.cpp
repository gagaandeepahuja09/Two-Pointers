class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
       int l = 0, r =  A.size() - 1;
        while(l < A.size() - 1 && A[l] <= A[l + 1]) {
            l++;
        }
        while(r > 0 && A[r] >= A[r - 1]) {
            r--;
        }
        if(r > l) {
            int mx = INT_MIN, mn = INT_MAX;
            for(int i = l; i <= r; i++) {
                mx = max(mx, A[i]);
                mn = min(mn, A[i]);
            }
            while(l >= 0 && A[l] > mn)
                l--;
            while(r < A.size() && A[r] < mx)
                r++;
        }
        return max(0, r - l - 1);
    }
};
