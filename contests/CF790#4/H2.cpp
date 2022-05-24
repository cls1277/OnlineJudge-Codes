//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(x) (x&(-x))
#define endl '\n'

const LL maxn = 2e5+5;
int a[maxn], n;
#define int LL

void add(int x, int y) {
    while(x) {
        a[x] += y;
        x -= lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while(x<=n) {
        res += a[x];
        x += lowbit(x);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int t; cin>>t;
    while(t--) {
        cin>>n; int ans = 0;
        Fo(i,1,n) a[i]=0;
        Fo(i,1,n) {
            int x; cin>>x;
            ans += sum(x);
            add(x, 1); 
            // cout<<ans<<' '; 
        }
        cout<<ans<<endl;
    }
    return 0;
}