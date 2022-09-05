#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int t = int(sqrt(n));
    if (t*t < n) {
        t += 1;
    }
    for (int i = t-1; i >= 0; i--) {
        for (int j = 1; j <= t; j++) {
            if (i*t+j<=n) cout << i*t+j << " ";
        }
    }
    cout << endl;
}

signed main()
{
    freopen("data.txt","r",stdin);
    cin.tie(nullptr)->sync_with_stdio(false);    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}