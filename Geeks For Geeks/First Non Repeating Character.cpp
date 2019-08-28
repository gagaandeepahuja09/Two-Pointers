#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        int idx = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while(mp[s[idx]] > 1)
                idx++;
        }
        if(idx >= s.size())
            cout << -1 << endl;
        else    
            cout << s[idx] << endl;
    }
	return 0;
}
