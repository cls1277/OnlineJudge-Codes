#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e7+7;
const int mod = 998244353;
const int inv2 = 499122177;

int pow2[maxn];
int frac[maxn];
int ifrac[maxn];

inline int binpow(int a, int q = mod - 2) {
    int res = 1;
    while (q) {
        if (q & 1) res = res * a % mod;
        a = a * a % mod;
        q >>= 1;
    }
    return res;
}

inline void init() {
    pow2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pow2[i] = (pow2[i-1] * 2) % mod;
    }
    frac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        frac[i] = (frac[i-1] * i) % mod;
    }
    ifrac[maxn-1] = binpow(frac[maxn-1]);
    for (int i = maxn-2; i >= 0; i--) {
        ifrac[i] = ifrac[i+1] * (i+1) % mod;
    }
}

inline int C(int n, int m) {
     return frac[n]*ifrac[m]%mod*ifrac[n-m]%mod;
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
    if (A == B) return inv2;
    return (dp(A-1, B) + dp(A, B-1))*inv2 % mod;
}

inline int solve(int A, int B) {
    int fz = 0;
    int fm = pow2[A+B-1];
    for (int i = 0; i < A; i++) {
        int k = C(A-i-2+B, A-i-1);
        fz = (fz + pow2[i]*k)%mod;
    }
    return fz * binpow(fm) % mod;
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    init();
    cin.tie(nullptr)->sync_with_stdio(false);    
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
    cout << memsearch((A+9)/10, (B+9)/10) << endl;
    cout <<163*binpow(256)%mod << endl;
    return 0;
}