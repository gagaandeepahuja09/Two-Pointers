class Solution {
public:
    int magicalString(int n) {
        vector<int> v;
        v = { 1, 2, 2};
        int cnt = 1;
        if(n == 0)
            return 0;
        if(n <= 3) {
            return 1;
        }
        int pos = 2, num = 1;
        for(int i = 2; i < n; i++) {
            for(int j = 0; j < v[i]; j++) {
                v.push_back(num);
                cnt += (num == 1);
                if(v.size() == n)
                    break;
            }
            num = 3 - num;
            if(v.size() == n)
                    break;
        }
        return cnt;
    }
};
