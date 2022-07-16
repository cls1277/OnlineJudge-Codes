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
        vector<LL> a(n);
        LL l=-1, cnt=0, sum=0;
        Fo(i,0,n-1) {
            LL x; cin>>x;
            if(!x&&i!=n-1) cnt++;
            if(i!=n-1&&l==-1&&x) l = i;
            if(i!=n-1) sum += x;
            a[i] = x;
        }
        // cout<<sum<<' '<<cnt<<' '<<l<<endl;
        if(l==-1) cout<<0<<endl;
        else cout<<sum+cnt-l<<endl; 
    }
    return 0;
}