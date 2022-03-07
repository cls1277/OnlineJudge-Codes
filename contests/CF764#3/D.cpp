//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

// const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL cnt[30]; Ms(cnt,0);
        LL n,k; cin>>n>>k;
        LL ans = 0;
        Fo(i,1,n) {
            char ch; cin>>ch;
            cnt[ch-'a']++;
        }
        LL even=0, odd=0;
        Fo(i,0,25) {
            even += cnt[i]/2*2;
            if(cnt[i]%2) odd++;
            // else even+=cnt[i];
        }
        // cout<<odd<<" "<<even<<endl;
        ans = even/k;
        // cout<<ans<<endl;
        odd += even%k;
        if(ans%2==0&&odd>=k)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}