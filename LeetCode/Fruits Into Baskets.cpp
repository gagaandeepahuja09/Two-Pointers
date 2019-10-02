class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i = 0, j = 0, cnt = 0, ret = 0;
        unordered_map<int, int> mp;
        while(i < tree.size()) {
            if(++mp[tree[i++]] == 1)
                cnt++;
            while(cnt > 2 && j <= i) {
              if(--mp[tree[j++]] == 0)
                  cnt--;
            }
            ret = max(ret, i - j + 1);
        }
        return ret;
    }
};
