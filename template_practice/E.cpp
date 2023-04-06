//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 25;
struct Node {
    LL a, b;
};

bool operator < (const Node &x, const Node &y) {
    return x.b<y.b;
}

Node a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL T; cin>>T;
    while(T--) {
        unordered_map<LL, bool> mp;
        LL n, m; cin>>n>>m;
        Fo(i,1,n) cin>>a[i].a;
        Fo(i,1,n) cin>>a[i].b;
        sort(a+1, a+n+1);
        LL mx = 0;
        Fo(i,1,n) {
            LL x =  a[i].b, t = a[i].a-1;
            while(t) {
                if(!mp[x]) {
                    mp[x] = 1;
                    t--;
                    x += a[i].b;
                } else {
                    x += a[i].b;
                }
            }
            mx = max(mx, x);
//            cout<<x<<endl;
        }
        //  cout<<mx<<endl;
        if(mx<=m) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
