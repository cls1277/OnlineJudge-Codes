//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 1e5+5;
LL n, m, t;
bool vis[maxn<<1];
vector<LL>e[maxn];
map<LL, LL>mp;
stack<LL>res;
LL ind[maxn], chd[maxn], cnt1, cnt2, s;

void dfs(LL x) {
    for(LL i=0; i<e[x].size(); i++) {
        LL to = e[x][i],id;
        id = mp[x*100000+to];
        // cout<<to<<" "<<id<<endl; //repeat edges!!!!!!
        if(vis[id]) continue;
        vis[id] = 1;
        dfs(to);
    }
    res.push(x);
    return ;
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    n=read(); m=read();
    //cin>>n>>m;
    Fo(i,1,m) {
        LL x,y; x=read(); y=read();//cin>>x>>y;
        chd[x]++; ind[y]++;
        e[x].push_back(y);
        mp[x*100000+y] = i;
    }
    s=1;
    Fo(i,1,n) {
        if(chd[i]-ind[i]==1) {
            cnt1++;
            s = i;
        }
        else if(ind[i]-chd[i]==1)
            cnt2++;
        else if(ind[i]!=chd[i]) {
            printf("No");
            // cout<<"No";
            return 0;
        }
        if(cnt1>1||cnt2>1) {
            printf("No");
            return 0;
        }
    }
    Fo(i,1,n) sort(e[i].begin(), e[i].end());
    dfs(s);
    while(!res.empty()) {
        printf("%lld ",res.top());
        // cout<<res.top()<<" ";
        res.pop();
    }
    // cout<<res.size();
    return 0;
}