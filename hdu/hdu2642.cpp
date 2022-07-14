//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'
#define lowbit(_) _&(-_)

const LL maxn = 1005;
LL tree[maxn][maxn], mp[maxn][maxn];

void update(LL x, LL y, LL z){
    for(int i=x; i<=1001; i+=lowbit(i))
        for(int j=y; j<=1001; j+=lowbit(j))
            tree[i][j] += z;
}
LL sum(LL x, LL y){
    LL res = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            res +=tree[i][j];
    return res;
}

LL ask(LL a, LL  b, LL c, LL d) {
    return sum(c, d)-sum(a-1, d)-sum(c, b-1)+sum(a-1, b-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        char op; cin>>op;
        if(op=='B') {
            LL x, y; cin>>x>>y;
            x++; y++;
            if(mp[x][y]) continue;
            mp[x][y] = 1;
            update(x, y, 1);
        } else if(op=='D') {
            LL x, y; cin>>x>>y;
            x++; y++;
            if(!mp[x][y]) continue;
            mp[x][y] = 0;
            update(x, y, -1);
        } else if(op=='Q') {
            pair<LL, LL> a, b; cin>>a.first>>b.first>>a.second>>b.second;
            a.first++; b.first++; a.second++; b.second++;
            cout<<ask(min(a.first, b.first), min(a.second, b.second), max(a.first, b.first), max(a.second, b.second))<<endl;
        }
    }
    return 0;
}