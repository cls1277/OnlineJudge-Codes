#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 5e5+5;
int a[maxn];
int b[maxn];
int bucket[maxn];
int n, m;


inline void run() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(bucket, 0, sizeof bucket);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b, b+m);
    
    for (int i = 0; i < n; ++i) {
        int l = 0, r = m-1;
        bool flag = false;
        while (l + 1 < r) {
            int mid = l + (r-l)/2;
            if (b[mid] == a[i]) {
                flag = true;
                break;
            } else if (b[mid] < a[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (flag) continue;
        for (int j = l; j <= r; ++j) {
            if (a[i] > b[j]) {
                bucket[j]++;
                break;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < m; ++i) {
        if (bucket[i] > ans) {
            ans = bucket[i];
        }
    }
    if (ans == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }
}

signed main()
{
    freopen("data.txt","r",stdin);
    cin.tie(nullptr)->sync_with_stdio(false);    
    int t;
    cin >> t;
    while (t--) {
        run();
    }
    return 0;
}
