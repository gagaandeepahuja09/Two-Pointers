class Solution {
public:
    bool canTransform(string s, string e) {
        string s1, s2;
        for(auto i : s) if(i != 'X')    s1 += i;
        for(auto i : e) if(i != 'X')    s2 += i;
        cout << s1 << " " << s2 << endl;
        if(s1 != s2)
            return false;
        int i = 0, j = 0;
        while(i < s.size() && j < e.size()) {
            if(s[i] == 'X') i++;
            else if(e[j] == 'X') j++;
            else { 
                if((s[i] == 'L' && i < j) || (s[i] == 'R' && i > j))
                    return false;
                i++;    j++;
            }
        }
        return true;
    }
};
