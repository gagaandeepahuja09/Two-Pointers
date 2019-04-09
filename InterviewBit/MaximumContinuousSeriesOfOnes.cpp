vector<int> Solution::maxone(vector<int> &A, int B) {
    int i = 0, j = 0, n = A.size(), cnt = 0, windowSize = -1, start = -1;
    while(j < n) {
        if(cnt <= B) {
            if(A[j] == 0)
                cnt++;
            j++;    
        }
        // We can't put else because above condn. will increase count
        if(cnt > B) {
            if(A[i] == 0)
                cnt--;
            i++;
        }
        if(j - i > windowSize) {
            windowSize = j - i;
            start = i;
        }
    }
    vector<int> ret;
    for(int i = start; i < start + windowSize; i++)
        ret.push_back(i);
    return ret;    
}

