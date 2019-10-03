class Solution {
public:
    string makePalin(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                s[r] = s[l];
            }
            l++; r--;
        }
        return s;
    }
    
    string nearestPalindromic(string s) {
        int l = 0, r = s.size() - 1;
        string curr = makePalin(s);
        long original = stoll(s), res = stoll(curr);
        long diff = abs(original - res);
        string ret = curr;
        long p = pow(10, (int)(s.size() / 2));
        long smaller = (original / p) * p - 1;
        long larger = (original / p) * p + p;
        string sm = to_string(smaller);
        sm = makePalin(sm);
        long sml = stoll(sm);
        if(diff == 0 || abs(original - sml) <= diff) {
            ret = sm;
            diff = abs(original - sml);
        }
        string lr = to_string(larger);
        lr = makePalin(lr);
        long lrl = stoll(lr);
        if(abs(original - lrl) < diff) {
            ret = lr;
        }
        // cout << sml << " " << lrl << endl; 
        return ret;
    }
};
