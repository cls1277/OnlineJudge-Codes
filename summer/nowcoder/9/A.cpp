#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+5;
int a[maxn];

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int i = 0, j = 0;
    int idx = 1;
    unordered_map<int, int> mp;
    while (j < n && mp.size() < m) {
        mp[a[j++]]++;
    }
    while (i < n) {
        if (mp[idx] == 0) break;
        ans += n - j + 1;
        idx = a[i++];
        mp[idx]--;
        while (j < n && mp[idx] == 0) {
            mp[a[j++]]++;
        }
    }
    cout << ans << endl;
    return 0;
}