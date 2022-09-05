#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, c;

void abc()
{
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
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
        cin >> a >> b >> c;
        abc();
        bool res = false;
        if (a == 1) {
            res = false;
        } else if (b == c || a == b) {
            res = true;
        } else {
            int cnt = 0;
            while (b - a + 1 < c) {
                c = b - a + 1;
                abc();
                cnt++;
            }
            res = cnt & 1;
        }

        cout << (res ? "Win" : "Lose") << endl;
    }
    return 0;
}