#include <bits/stdc++.h>
using namespace std;
#define int long long

// int qpow(int x, int y) {
//     int z = 1
// }

signed main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    // cout<<x<<' '<<y<<endl;
    int t = x ^ y;
    t = 2305843009213693951;
    if (t < x) {
        cout << 1 << endl;
        cout << t << endl;
    } else {
        int len = 0;
        int tt = t;
        while (tt) {
            len++;
            tt >>= 1;
        }
        cout<<len<<endl;
        int a = 1ll << (len - 1);
        int b = t - a;
        cout << 2 << endl;
        cout << b << " " << a << endl;
    }
    return 0;
}
