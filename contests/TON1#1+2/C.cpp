//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 1e5+5;
LL n, a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        bool flag1=0, flag2=0;
        Fo(i,1,n) {
            cin>>a[i];
            if(a[i]==1) flag1=1;
        }
        sort(a+1,a+n+1);
        Fo(i,1,n-1)
            if(a[i+1]-a[i]==1) {
                flag2 = 1;
                break;
            }
        if(flag1&&flag2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}