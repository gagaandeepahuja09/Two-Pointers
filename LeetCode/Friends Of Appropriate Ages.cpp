class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        auto low = lower_bound(ages.begin(), ages.end(), ages[0] / 2 + 8);
        auto high = upper_bound(ages.begin(), ages.end(), ages[0]);
        int ans = 0;
        for(int i = 0; i < ages.size(); i++) {
            while(*low < ages[i] / 2 + 8) {
                low++;
            }
            while(high != ages.end() && *high <= ages[i]) {
                high++;
            }
            int request = distance(low, high) - 1;
            ans += max(request, 0);
        }
        return ans;
    }
};
