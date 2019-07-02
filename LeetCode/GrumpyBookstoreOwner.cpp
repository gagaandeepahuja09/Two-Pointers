class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int k) {
        int ans = 0, sum = 0;
        for(int i = 0; i < c.size(); i++) {
            if(!g[i])
                sum += c[i];
        }
        ans = max(ans, sum);
        
        for(int i = 0; i < k; i++) {
            if(g[i])
                sum += c[i];
            ans = max(ans, sum);
        }
        
        for(int i = k; i < c.size(); i++) {
            if(g[i])
                sum += c[i];
            if(g[i - k])
                sum -= c[i - k];
            ans = max(ans, sum);
        }
        return ans;
    }
};
