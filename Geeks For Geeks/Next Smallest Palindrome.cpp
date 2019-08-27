#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> v = a;
        int l, r;
        if(n % 2 == 0) {
            r = n / 2;
            l = r - 1;
        }
        else {
            l = r = n / 2;
        }
        while(l >= 0 && r < n) {
            if(a[l] != a[r]) {
                a[r] = a[l];
            }
            l--; r++;
        }
        string original = "", palin = "";
        for(int i = 0; i < v.size(); i++)
            original += (char)(v[i] + '0');
        for(int i = 0; i < a.size(); i++)
            palin += (char)(a[i] + '0');
        int carry = 0;    
        if(palin <= original) {
            carry = 1;
            if(n % 2 == 0) {
                r = n / 2;
                l = r - 1;
                a[l]++;
                carry = a[l] / 10;
                a[l] %= 10;
                a[r]++;
                carry = a[r] / 10;
                a[r] %= 10;
                l--; r++;
            }
            else {
                l = r = n / 2;
                a[l]++;
                carry = a[l] / 10;
                a[l] %= 10;
                // cout << "t " << a[l] << endl;
                l--; r++;
            }
            while(carry && l >= 0 && r < n) {
                int c = carry;
                a[l] += c;
                a[r] += c;
                carry = a[l] / 10;
                a[l] %= 10;
                a[r] %= 10;
                l--; r++;
            }
        }  
        for(int i = 0; i < a.size(); i++)
            cout << a[i] << " "; 
        cout << endl;   
    }
	return 0;
}
