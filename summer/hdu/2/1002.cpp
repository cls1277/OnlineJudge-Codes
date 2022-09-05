#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char str[1024];

signed main()
{
    freopen("data.txt","r",stdin);
    cin.tie(nullptr)->sync_with_stdio(false);    
	int T;
    cin >> T;
    while (T--) {
        cin >> str;
        for (const auto& i : str) {
            if ((i >= '0' && i <= '9') || i == '(' || i ==')'||i==','||i=='-') {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}