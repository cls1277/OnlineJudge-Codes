#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 2e6+6;

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

inline ULL qmul(ULL a, ULL b, const ULL mod){
    LL c=(LL)(a)*b-(LL)((ULL)((LD)(a)*b/mod)*mod);
    return c<0? c+mod:(c<mod? c:c-mod);
}

inline ll qpow(ll a, ll b, ll mod = 19260817) {
    ll res = 1;
    while(b) {
        if(b&1)
            res = qmul(res,a,mod);
        a = qmul(a,a,mod);
        b>>=1;
    }
    return res;
}

bool miller_rabin(ll n, int repeat)//n是测试的大数，repeat是测试重复次数
{
    if(n == 2 || n == 3)return true;//特判
    if(n % 2 == 0 || n == 1)return false;//偶数和1

    //将n-1分解成2^s*d
    ll d = n - 1;
    int s = 0;
    while(!(d & 1)) ++s, d >>= 1;
    srand((unsigned)time(NULL));
    for(int i = 0; i < repeat; i++)//重复repeat次
    {
        ll a = rand() % (n - 3) + 2;//取一个随机数,[2,n-1)
        ll x = qpow(a, d, n);
        ll y = 0;
        for(int j = 0; j < s; j++)
        {
            y = qmul(x, x, n);
            if(y == 1 && x != 1 && x != (n - 1))return false;
            x = y;
        }
        if(y != 1)return false;//费马小定理
    }
    return true;
}

void solve() {
    ll p, q, e, m = 1e9+7;
    cin >> p >> q >> e;
    ll km = p*q-1;
    ll minm = max(p, max(q, e)) + 1;
    ll ans = -1;
    for (ll k = 1; k < maxn; k++) {
        if (km / k < minm) {
            break;
        }
        if (km % k == 0) {
            m = km / k;
            bool isp = miller_rabin(m, 50);
            if (!isp) {
                continue;
            }
            // 此时已经保证 p * q == 1 (mod m)
            ans = (e * q) % m;
            if ((ans * p) % m != e) {
                ans = -1;
            }
        }
    }
    if (ans == -1) {
        cout << "shuanQ" << endl;
    } else {
        cout << ans << endl;
    }
}

signed main()
{
	freopen("data.txt","r",stdin);
	freopen("out.txt","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);    
	int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
