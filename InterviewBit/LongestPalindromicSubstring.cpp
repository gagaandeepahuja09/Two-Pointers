void findMatch(int l, int h, string A, int& mx, int &L, int &H) {
    while(l >= 0 && h < A.size() && A[l] == A[h]) {
        if(mx < h - l + 1) {
            mx =  h - l + 1;
            L = l;
            H = h;
            // cnt++;
        }
        l--; h++;
    }
}

string Solution::longestPalindrome(string A) {
    int mx = 0, L = 0, H = 0;
    for(int i = 0; i < A.size(); i++) {
        findMatch(i - 1 , i + 1, A, mx, L, H);
        findMatch(i, i + 1, A, mx, L, H);
    }
    return A.substr(L, H - L + 1);
    // return cnt + A.size();
}
