#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int N = 1e6 + 5, mod = 998244353;
deque<int>q;
int a[N], t[N];
bool f[N];
signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        t[a[i]]++;
    }
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        t[a[i]]--;
        if (f[a[i]]) continue;
        while(a[i] <= q.back() && t[q.back()]) {
            f[q.back()] = 0;
            q.pop_back();
        }
        q.push_back(a[i]);
        f[a[i]] = 1;
    }

    q.pop_front();
    cout << q.front();
    q.pop_front();
    while(!q.empty()) {
        printf(" %d", q.front());
        q.pop_front();
    }
    return 0;
}
