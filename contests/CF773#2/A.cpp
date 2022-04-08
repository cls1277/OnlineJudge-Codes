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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL x, y, z, a, b, c;
        cin>>x>>a>>y>>b>>z>>c;
        if(a==b&&c<a) cout<<abs(y-x)<<endl;
        else if(a==c&&b<a) cout<<abs(z-x)<<endl;
        else if(b==c&&a<b) cout<<abs(z-y)<<endl;
        else cout<<0<<endl;
    }
    return 0;
}