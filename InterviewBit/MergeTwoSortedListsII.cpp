void Solution::merge(vector<int> &A, vector<int> &B) {
    int i = 0, j = 0;
    vector<int> res;
    while(i < A.size() && j < B.size()) {
        if(A[i] <= B[j]) {
            i++;
        }
        else {
            A.insert(A.begin() + i, B[j]);
            i++;
            j++;
        }
    }
    while(j < B.size()) {
        A.push_back(B[j]);
        j++;
    }
}

