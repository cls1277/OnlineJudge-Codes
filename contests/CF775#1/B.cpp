//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e6+5;
LL n, c, f[maxn];
bool vis[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>c;
        // Ms(vis, 0); Ms(f, 0);
        // Fo(i,1,c) vis[i]=f[i]=0;
        Fo(i,1,n) {
            LL x; cin>>x;
            f[x] = vis[x] = 1;
        }
        Fo(i,1,2*c) f[i] += f[i-1];
        bool flag = 1;
        Fo(i,1,c) {
            if(!vis[i]) continue;
            for(int j=i; j<=c; j+=i) {
                if(!vis[j/i]&&f[j+i-1]-f[j-1]!=0) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        Fo(i,1,2*c) vis[i]=f[i]=0;
    }
    return 0;
}