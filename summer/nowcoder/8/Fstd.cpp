#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 6;


int LIS(const vector<int>& seq) {
    vector<int> dp;
    for (const auto& i : seq) {
        auto it = lower_bound(dp.begin(), dp.end(), i);
        if (it == dp.end()) {
            dp.push_back(i);
        } else {
            *it = i;
        }
    }
    return dp.size();
}

void solve()
{
    unordered_set<int> ss, st;
    vector<int> s, t;
    int n, m, p, x, a, b, c;
    cin >> n >> m >> p >> x >> a >> b >> c;

    for (int i = 0; i < n; i++) {
        x = (a * x % p * x + b * x + c) % p;
        // cout << x << " ";
        s.push_back(x);
        ss.insert(x);
    }
    // cout << endl;
    for (int i = 0; i < m; i++) {
        x = (a * x % p * x + b * x + c) % p;
        // cout << x << " ";
        if (ss.find(x) != ss.end()) {
            t.push_back(x);
            st.insert(x);
        }
    }
    // cout << endl;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (st.find(s[i]) != st.end()) {
            s[idx++] = s[i];
        }
    }
    s.erase(s.begin() + idx, s.end());

    unordered_map<int, set<int, greater<int> > > mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]].insert(i);
    }

    vector<int> seq;
    for (const auto& i : t) {
        for (const auto& j : mp[i]) {
            seq.push_back(j);
        }
    }
    
    cout << LIS(seq) << endl;
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
