//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 4e3+5;
vector<int>son[maxn];
string str;
int ans;

pair<int, int> dfs(int u, int b, int w) {
    // int x=b, y=w;
    int x = 0, y = 0;
    if(str[u-1]=='B') x++;
    else y++;
    for(auto v:son[u]) {
        if(str[v-1]=='B') {
            auto it = dfs(v, 1, 0);
            x += it.first;
            y += it.second;
        } else {
            auto it = dfs(v, 0, 1);
            x += it.first;
            y += it.second;
        }
    }
    // cout<<u<<' '<<x<<' '<<y<<endl;
    if(x==y) ans++;
    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        Fo(i,1,n) son[i].clear();
        ans = 0;
        Fo(i,2,n) {
            int x; cin>>x;
            son[x].push_back(i);
        }
        cin>>str;
        if(str[0]=='B') dfs(1, 1, 0);
        else dfs(1, 0, 1);
        cout<<ans<<endl;
        // break;
    }
    return 0;
}