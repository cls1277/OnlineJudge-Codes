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
        LL n; cin>>n;
        cout<<2<<endl;
        vector<bool> a(n+1, 0);
        Fo(i,1,n) {
            if(a[i]) continue;
            for(int j=i; j<=n; j*=2) {
                if(a[j]) continue;
                cout<<j<<' ';
                a[j] = 1;
            }
        }
        cout<<endl;
    }
    return 0;
}