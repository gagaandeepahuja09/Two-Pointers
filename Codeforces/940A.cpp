#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        while(j < n && a[i] - a[j] > d) {
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << (n - ans) << endl;
	return 0;
}
