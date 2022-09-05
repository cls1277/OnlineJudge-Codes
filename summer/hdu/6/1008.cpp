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
unordered_map<LL, LL> value;

void build(LL id, LL l, LL r){
    value[id] += r-l+1;
    if(l == r) return;
    LL mid = (r+l)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; scanf("%lld",&t); //cin>>t;
    while(t--) {
        LL n, x; scanf("%lld%lld", &n,&x);//cin>>n>>x;
        value.clear();
        Fo(i,1,n) build(1, 1, i);
        printf("%lld\n",value[x]);
    }
    return 0;
}