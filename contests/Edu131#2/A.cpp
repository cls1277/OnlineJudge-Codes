//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL cnt = 0;
        Fo(i,1,2) {
            Fo(j,1,2) {
                LL x; cin>>x;
                if(x==1) cnt++;
            }
        }
        if(cnt==4) cout<<2<<endl;
        else if(!cnt) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}