//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;
LL n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        map<LL, LL> vis, vis2;
        cin>>n>>m;
        Fo(i,1,n) {
            LL x; cin>>x;
            vis2[x] = i;
            if(vis[x]) continue;
            vis[x] = i;
        }
        Fo(i,1,m) {
            LL l, r; cin>>l>>r;
            if(!vis[l]||!vis[r]||!vis2[l]||!vis2[r]) {
                cout<<"NO"<<endl;
            } else {
                if(vis[l]<vis2[r]) {
                    cout<<"YES"<<endl;
                } else {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}