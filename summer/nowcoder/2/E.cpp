#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 998244353;
const ll maxn = 1e6 + 6;
ll fac[maxn]; // 阶乘
ll faci[maxn]; // 阶乘的逆元
// ll inv[maxn];
ll pow26[maxn];
ll arr[maxn];

ll binpow(ll a, ll q)
{
    a %= mod;
    q %= mod;
    ll res = 1;
    while (q) {
        if (q & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        q >>= 1;
    }
    return res % mod;
}

void init()
{
    // 预处理阶乘
    fac[0] = 1;
    for (ll i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    // 线性求组合数逆元
    faci[maxn - 1] = binpow(fac[maxn - 1], mod - 2);
    for (ll i = maxn - 2; i >= 0; i--) {
        faci[i] = faci[i + 1] * (i + 1) % mod;
    }
    // // 线性求逆元
    // inv[1] = 1;
    // for (ll i = 2; i < maxn; i++) {
    //     inv[i] = (mod - (mod/i))*inv[mod%i] % mod;
    // }
    pow26[0] = 1;
    for (ll i = 1; i < maxn; i++) {
        pow26[i] = pow26[i - 1] * 26 % mod;
    }
}

ll C(ll n, ll m)
{
    if (m >= n)
        return 1;
    return fac[n] * faci[m] % mod * faci[n - m] % mod;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    ll n;
    while(cin >> n){
    if (n < 3) {
        for (ll i = 0; i <= n; i++) {
            cout << "0 ";
        }
        cout << endl;
        return 0;
    }
    for (ll i = n / 3 + 1; i <= n; i++) {
        arr[i] = 0;
    }
    for (ll i = n / 3; i >= 0; i--) {
        arr[i] = fac[n - 2 * i] * faci[i] % mod * faci[n - 3 * i] % mod * pow26[n - 3 * i] % mod;
        for (ll j = n / 3; j > i; j--) {
            arr[i] = (mod + arr[i] - arr[j] * C(j, i) % mod) % mod;
        }
    }
    // ll s = 0;
    // 测试1
    // for (ll i = 0; i < n/3; i++) {
    //     arr[i] = (arr[i] - arr[i+1] + mod) % mod;
    // }
    // 测试2
    // ll ss = 0;
    // for (ll i = n/3; i >= 0; i--) {
    //     arr[i] = (arr[i] - ss + mod) % mod;
    //     s = (arr[i] - s + mod) % mod;
    //     ss = (ss + 2*s) % mod;
    // }
    // 输出
    for (ll i = 0; i <= n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
    }
    // 验证
    // s = 0;
    // for (ll i = 0; i <= n; i++) {
    //     s = (s + arr[i]) % mod; 
    // }
    // cout << (s == pow26[n]) << endl;
    return 0;
}