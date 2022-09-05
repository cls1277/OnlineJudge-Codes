#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);    
    int x, y;
    cin >> x >> y;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        if (a >= x) {
            cout<<1;
            return 0;
        } 
        //return 1;
        x ^= a;
    }
    if (x != y) {
        cout<<1;
        return 0;
    }
    cout<<0;
    return 0;
}