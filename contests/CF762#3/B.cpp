//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = ;
map<LL,bool>vis;
vector<LL>d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    Fo(i,1,100000) {
        LL b=i*i , c=b*i;
        if(b<=1000000000&&!vis[b]) {
            vis[b] = 1;
            d.push_back(b);
        }
        if(c<=1000000000&&!vis[c]) {
            vis[c] = 1;
            d.push_back(c);
        }
    }
    sort(d.begin(),d.end());
    LL t; cin>>t;
    while(t--) {
        LL a; cin>>a;
        LL idx = upper_bound(d.begin(),d.end(),a)-d.begin();
        cout<<idx<<endl;
    }
    return 0;
}