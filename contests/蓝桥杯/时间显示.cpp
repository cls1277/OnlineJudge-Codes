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
    LL n; cin>>n;
    n%=86400000;
    LL h = n/3600000;
    LL m = (n-h*3600000)/60000;
    LL f = (n-h*3600000-m*60000)/1000;
    if(h>=10) cout<<h;
    else cout<<'0'<<h;
    cout<<':';
    if(m>=10) cout<<m;
    else cout<<'0'<<m;
    cout<<':';
    if(f>=10) cout<<f;
    else cout<<'0'<<f;    
    return 0;
}