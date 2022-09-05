#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string str;
    getline(cin, str);
    bool flag = true;
    for (const auto& i: str) {
        cout<<i<<' ';
        if (flag) {
            // cout << char(i - 'a' + 'A');
            flag = false;
        } else if (i == ' ') {
            flag = true;
        }
    }
    cout << endl;
}

signed main()
{
    freopen("data.txt","r",stdin);
    // cin.tie(nullptr)->sync_with_stdio(false);    
	int n;
    // cin >> n;
    scanf("%lld\n",&n);
    while (n--) {
        solve();
    }
    return 0;
}