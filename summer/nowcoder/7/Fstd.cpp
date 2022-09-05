#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e5 + 5;
int a[maxn];

namespace us {
int par[maxn];

void init(int n)
{
    par[0] = n-1;
    for (int i = 1; i < maxn; i++) {
        par[i] = i-1;
    }
}

// 前面那个数是什么
int find(int x)
{
    return par[x];
}

void unio(int x)
{
    int pre = find(x);
    int pre2 = find(pre);
    par[x] = find(pre2);
    par[pre] = find(pre2);
    par[pre2] = find(pre2);
}

void print() {
    for (int i = 0; i < 10; i++) {
        cout << par[i] << " ";
    }
    cout << endl;
}

} // namespace us

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    us::init(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int pre = us::find(i);
        int pre2 = us::find(pre);
        if (a[pre] == a[pre2] || a[pre] + a[pre2] == x) {
            // cnt++;
            // us::unio(i);
            // // cout << "UNION " << pre << " " << pre2 << endl;
            // // us::print();
        } else {
            idx = i;
            break;
        }
    }
    if (idx == -1) idx = 0;
    for (int ii = 0; ii < n; ii++) {
        int i = (ii+idx)%n;
        int pre = us::find(i);
        int pre2 = us::find(pre);
        if (a[pre] == a[pre2] || a[pre] + a[pre2] == x) {
            cnt++;
            us::unio(i);
            // // cout << "UNION " << pre << " " << pre2 << endl;
            // // us::print();
        }
    }
    cout << cnt << endl;
    return 0;
}