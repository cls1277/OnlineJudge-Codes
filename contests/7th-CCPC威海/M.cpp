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
LL n, m, k;

LL dfs(LL a, LL b, LL c) {
    if(!a||!b) return 1;
    if(c==1) return 2;
    if(b==c) return a+1;
    return dfs(a-1, b, c)+dfs(a, b-1, c-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>k;
    cout<<dfs(n-m, m, k);
    return 0;
}