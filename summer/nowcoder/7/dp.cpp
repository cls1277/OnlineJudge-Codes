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
    // freopen("C_.txt","r",stdin);
    #endif
    LL n; cin>>n;
    vector<LL> a(n+1);
    Fo(i,1,n) {
        cin>>a[i];
    }
    bool flag = 1;
    Fo(i,1,n) {
        LL x; cin>>x;
        if(a[i]==x) {
            flag = 0;
            break;
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}