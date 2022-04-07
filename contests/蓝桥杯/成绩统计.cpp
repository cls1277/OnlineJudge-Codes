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
    LL n, a=0, b=0; cin>>n;
    Fo(i,1,n) {
        LL x; cin>>x;
        if(x>=60) a++;
        if(x>=85) b++;
    }
    cout<<int(a*1.0/n*100+0.5)<<'%'<<endl;
    cout<<int(b*1.0/n*100+0.5)<<'%';
    return 0;
}