#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 105

int main() {
    //ll t;
    //cin >> t; while(t--) {
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    ll l = 0, r = 0, sum = p[0].second, ans = 0;
    while(l < n && r < n) {
        if(r < l) {
            r++;
            sum += p[r].second;
        }
        if(p[r].first - p[l].first < d) {
            ans = max(ans, sum);
            r++;
            sum += p[r].second;
        }
        else {
            sum -= p[l].second;
            l++;
        }
    }
    cout << ans << endl;
    // }
}
