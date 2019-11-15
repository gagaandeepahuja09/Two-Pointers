class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int l = 0, n = A.size();
        if(x >= A[n - 1]) {
            l = n - 1;
        }
        else if(x <= A[0]) {
            l = 0;
        }
        else {
            for(int i = 0; i < n - 1; i++) {
                if(A[i] <= x && A[i + 1] >= x) {
                    l = i;
                    break;
                }
            }   
        }
        int r = l + 1;
        vector<int> ret;
        while((l >= 0 || r < n) && ret.size() < k) {
            if(l >= 0 && r < n) {
                if(abs(A[l] - x) <= abs(A[r] - x)) {
                    ret.push_back(A[l--]);;    
                }
                else {
                    ret.push_back(A[r++]);
                }
            }
            else if(l >= 0) {
                ret.push_back(A[l--]);;    
                }
            else {
                ret.push_back(A[r++]);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
