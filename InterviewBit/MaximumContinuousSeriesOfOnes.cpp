vector<int> Solution::maxone(vector<int> &A, int m) {
    int n = A.size();
    vector<int> ret;
    int l = 0, r = 0, c0 = 0, start = -1, mx = 0;
    while(r < n) {
        if(c0 <= m) {
            if(A[r] == 0)
                c0++;
            r++;
        }
        if(c0 > m) {
            if(A[l] == 0)
                c0--;
            l++;    
        }
        if(r - l + 1 > mx) {
            mx = r - l + 1;
            start = l;
        }       
    }
    if(start != -1) {
        for(int i = start; i < start + mx - 1; i++) {
            ret.push_back(i);
        }
    }
    return ret;
}

