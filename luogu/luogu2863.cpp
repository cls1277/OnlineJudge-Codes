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

const LL maxn = 1e4+5;
// const LL maxm = 5e4+5;
LL n, m;
vector<LL>e[maxn];
LL dfn[maxn], low[maxn], idx, cnt, res[maxn], ans;
bool ins[maxn];
stack<LL>s;

void tarjan(LL x) {
    dfn[x] = low[x] = ++idx;
    s.push(x); ins[x] = 1;
    for(LL i=0; i<e[x].size(); i++) {
        LL v=e[x][i];
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x],low[v]);
        } else if(ins[v]) {
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]) {
        cnt++; LL temp;
        do {
            temp = s.top();
            ins[temp] = 0;
            s.pop();
            res[cnt]++;
        }while(temp!=x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,m) {
        LL x,y; cin>>x>>y;
        e[x].push_back(y);
    }
    Fo(i,1,n)
        if(!dfn[i])
            tarjan(i);
    // cout<<cnt<<endl;
    Fo(i,1,cnt)
        if(res[i]>1)
            ans++;
    cout<<ans;
    return 0;
}