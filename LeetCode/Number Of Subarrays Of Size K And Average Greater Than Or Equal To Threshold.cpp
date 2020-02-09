class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double th = (double)threshold;
        double sum = 0;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(i >= k)
                sum -= arr[i - k];
            if(i >= k - 1) {
                double avg = sum / (double)k;
                if(avg >= th)
                    cnt++;
            }
        }
        return cnt;
    }
};
