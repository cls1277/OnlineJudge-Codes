#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);    
    ll n;
    cin >> n;
    ll l = 1, r = 1;
    for (ll i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        if (i <= r) {
            r = max(r, i+t);
        }
    }
    cout << r << endl;
    return 0;
}
