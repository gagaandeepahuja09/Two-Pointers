class Solution {
public:
    int atMost(vector<int>& A, int K) {
        int s = 0, cnt = 0, ret = 0;
        unordered_map<int, int> mp;
        /* for(int i=0; i<A.size(); i++) {
            mp[A[i]]++;
            while(mp.size() > K) {
                mp[A[s]]--;
                if(mp[A[s]] == 0)
                    mp.erase(A[s]);
                s++;
            }
            ret += (i - s + 1);
        } */
        for(int i = 0; i < A.size(); i++) {
            if(!mp[A[i]]++)
                cnt++;
            while(cnt > K) {
                if(!--mp[A[s++]])
                    cnt--;
            }
            ret += (i - s + 1);
        }
        cout << ret << endl;
        return ret;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMost(A, K) - atMost(A, K - 1);
    }
};
