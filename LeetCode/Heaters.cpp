class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size(), m = heaters.size(), j = 0;
        vector<int> rhs(n, INT_MAX), lhs(n, INT_MAX);
        for(int i = 0; i < n; i++) {
            while(j < m && heaters[j] < houses[i]) {
                j++;
            }
            if(j < m)
                rhs[i] = heaters[j] - houses[i];
        }
        j = m - 1;
        int ret = 0;
        for(int i = n - 1; i >= 0; i--) {
            while(j >= 0 && heaters[j] > houses[i]) {
                j--;
            }
            if(j >= 0)
                lhs[i] = houses[i] - heaters[j];
            lhs[i] = min(lhs[i], rhs[i]);
            ret = max(ret, lhs[i]);
        }
        return ret;
    }
};
