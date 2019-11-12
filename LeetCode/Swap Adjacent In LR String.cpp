class Solution {
public:
    bool canTransform(string s, string e) {
        if(s.size() != e.size())
            return false;
        int lc = 0, rc = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'L')
                lc++;
            if(e[i] == 'L')
                lc--;
            if(s[i] == 'R')
                rc++;
            if(e[i] == 'R')
                rc--;
        }
        if(lc || rc)
            return false;
        int i = 0, j = 0, n = s.size();
        while(i < n && j < n) {
            while(s[i] == 'X')  i++;
            while(e[j] == 'X')  j++;
            if(i == s.size() && j == e.size())
                return true;
            if(i == s.size() || j == e.size() || s[i] != e[j])
                return false;
            if(s[i] == 'L' && i < j)
                return false;
            if(s[i] == 'R' && i > j)
                return false;
            i++; j++;
        }
        return true;
    }
};
