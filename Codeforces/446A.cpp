#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 200005

ll n, q;

int main() {
// ll t;
// cin >> t; while(t--) {
ll n, m;
cin >> n >> m;
vector<ll> a(n);
for(int i = 0; i < n; i++) {
    cin >> a[i];
}
ll ans = 0;
vector<ll> l(n), r(n);
l[0] = 1;
for(int i = 1; i < n; i++) {
    if(a[i] > a[i - 1])
        l[i] = 1 + l[i - 1];
    else
        l[i] = 1;
}
r[n - 1] = 1;
for(int i = n - 2; i >= 0; i--) {
    if(a[i] < a[i + 1])
        r[i] = 1 + r[i + 1];
    else
        r[i] = 1;
}
for(int i = 1; i < n; i++) {
    if(a[i - 1] + 1 < a[i + 1])
        ans = max(ans, 1 + l[i - 1] + r[i + 1]);
    else
        ans = max(ans, 1 + max(l[i - 1], r[i + 1]));
}
cout << ans << endl;
// }
}
