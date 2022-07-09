//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL a[maxn], b[maxn], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>a[i];
    LL c=0, d=0;
    Fo(i,2,n) {
        if(a[i]-a[i-1]>0) c+=a[i]-a[i-1];
        else d+=a[i-1]-a[i];
    }
    cout<<max(c,d)<<endl<<abs(c-d)+1;
    return 0;
}