class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int l = 1, r = k + 1;
        vector<int> ret;
        while(l <= r) {
            ret.push_back(l++);
            if(l <= r)
                ret.push_back(r--);
        }
        for(int i = k + 2; i <= n; i++)
            ret.push_back(i);
        return ret;
    }
};
