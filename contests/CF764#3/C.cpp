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

const LL maxn = 55;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL T; cin>>T;
    while(T--) {
        LL a[maxn];
        bool vis[maxn], ans=1; Ms(vis,0);
        LL n; cin>>n;
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) {
            LL cnt = 0;
            while(a[i]>n) a[i]>>=1;
            while(1) {
                if(!vis[a[i]]) {
                    vis[a[i]] = 1;
                    cnt++;
                    break;
                }
                if(a[i]==1) break;
                a[i]>>=1;
            }
            if(!cnt) {
                ans = 0;
                break;
            }
        }
        // Fo(i,1,n) cout<<vis[i]<<" ";
        // cout<<endl;
        Fo(i,1,n)
            ans=ans&vis[i];
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}