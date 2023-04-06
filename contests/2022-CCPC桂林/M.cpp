#include <bits/stdc++.h>
#include <deque>
#include <iterator>
using namespace std;
using ll = long long;
const ll maxn = 3e5+5;
ll n, m;
ll t[maxn];

ll lowbit(ll x)
{
	return x&-x;
}
ll add(ll x)//把包含这个数的结点都更新 
{
	while(x<=n)//范围 
	{
		t[x]++;
		x+=lowbit(x);
	}
}
ll sum(ll x)//查询1~X有几个数加进去了 
{
	ll res=0;
	while(x>=1)
	{	
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}

signed main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    deque<ll> d(n);
    // set<ll> st;
    ll cnt = 0;
    for (auto &x : d) {
        cin >> x;
        // cnt += distance(st.lower_bound(x), st.end());
        // st.insert(x);
        add(x);
        cnt += sum(x-1);
    }
    string s;
    cin >> s;

    cnt = n*(n-1)/2 - cnt;

    bool rev = false;
    cout << cnt << endl;

    for (const auto &op : s) {
        if (op == 'S') {
            ll x;
            if (rev) {
                x = d.back();
                d.pop_back();
                d.push_front(x);
            } else {
                x = d.front();
                d.pop_front();
                d.push_back(x);
            }
            cnt = (cnt - x + 1 + n - x + 10 * n) % 10;
        } else {
            rev = !rev;
            cnt = (n * (n - 1) / 2 % 10 - cnt + 10 * n) % 10;
        }
        cout << cnt % 10;
    }
    cout << endl;
    return 0;
}
