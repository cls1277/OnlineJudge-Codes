#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const ll maxn = 1e5 + 5;
ll a[maxn];

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;
    while (cin >> n >> m) {
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        // (k+1)*k/2;
        sort(a, a + n);
        bool flag = true; // 是否需要输出n
        ll s = 0;
        for (ll i = 0; i < n; i++) {
            s += a[i];
            // cout << s << " " << i << endl;
            if (s + (i + 1) * (i + 1) * (i + 2) / 2 > m) {
                cout << i << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << n << endl;
        }
    }
    return 0;
}