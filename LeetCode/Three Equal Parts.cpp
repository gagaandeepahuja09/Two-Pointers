class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int c1 = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == 1)  
                c1++;
        }
        if(c1 == 0) {
            return { 0, (int)A.size() - 1 };
        }
        if(c1 % 3) {
            return { -1, -1 };
        }
        int start = 0, mid = 0, end = 0;
        for(start = 0; start < A.size() && A[start] == 0; start++);
        int c = 0;
        for(mid = start; mid < A.size(); mid++) {
            if(A[mid] == 1)
                c++;
            if(c == c1 / 3 + 1)
                break;
        }
        c = 0;
        for(end = mid; end < A.size(); end++) {
            if(A[end] == 1)
                c++;
            if(c == c1 / 3 + 1)
                break;
        }
        while(end < A.size() && A[start] == A[mid] && A[mid] == A[end])
            start++, mid++, end++;
        if(end == A.size())
           return { start - 1, mid }; 
        return { -1, -1 }; 
    }
};
