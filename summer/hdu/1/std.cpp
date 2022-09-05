#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 1<<10;

set<int> s[maxn]; 

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        s[i].clear();
    }
    s[0].insert(0);
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            for (const auto& k: s[j-v]) {
                s[j].insert(k^w);
            }
        }
    }
    if (s[m].size() == 0) {
        cout << -1 << endl;
    } else {
        if(*s[m].crbegin()>1023) cout<<1023<<endl;
        else cout<<*s[m].crbegin();
    }
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
