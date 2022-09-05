#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define int long long

const int mod = 998244353;
const int inv2 = 499122177;

inline int binpow(int a, int q = mod - 2) {
    int res = 1;
    while (q) {
        if (q & 1) res = res * a % mod;
        a = a * a % mod;
        q >>= 1;
    }
    return res;
}

map<pair<int, int>, int> mp;

int memsearch(int A, int B);

int dp(int A, int B) {
    auto k = make_pair(A, B);
    if (mp.find(k) != mp.end()) return mp[k];
    else mp[k] = memsearch(A, B);
    return mp[k];
}

int memsearch(int A, int B) {
    if (A <= 0) return 0;
    if (B <= 0) return 1;
    return (dp(A-10, B) + dp(A, B-10))*inv2 % mod;
}

int solve(int A, int B) {
    if (A == B) {
        return inv2;
    } else if (A < B) {
        int s = 0;
        for (int i = 1; i <= A; i++) {
            s = (s + i * i) % mod;
        }
        return s * binpow(binpow(2, A+B-1)) % mod;
    } else {
        int s = 0;
        for (int i = 1; i <= B; i++) {
            s = (s + i * i) % mod;
        }
        int ab = binpow(2, A+B-1);
        return (ab - s) * binpow(ab) % mod;
    }
    return 0;
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);    
    // cout << binpow(2) << endl;
    // cout << binpow(4) << endl;
    int A, B, t;
    cin >> A;
    for (int i = 0; i < 7; i++) {
        cin >> t;
    }
    cin >> B;
    for (int i = 0; i < 7; i++) {
        cin >> t;
    }
    cout << solve((A+9)/10, (B+9)/10) << endl;
    // cout << 3*binpow(binpow(2, 2))%mod << endl;
    return 0;
}