//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// 在本题中，此做法空间消耗太大
const LL maxn = 5e5*4+5;

LL n, m, s;

struct Node {
    LL to, next;
}e[maxn<<1];

LL head[maxn], tot, deep[maxn], cnt, first[maxn];
pair<LL, LL> st[maxn][25]; //first:deep, second:id
vector<pair<LL, LL>> a;

pair<LL, LL> calc(pair<LL, LL> x, pair<LL, LL> y) {
    if(x.first < y.first) return x;
    return y;
}

void add(LL x, LL y) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    head[x] = tot;
}

void dfs(LL x, LL f) {
    first[x] = cnt;
    // a.push_back({deep[x], x}); cnt++;
    bool flag = 0;
    Eo(i, x, e) {
        LL v = e[i].to;
        if(v==f) continue;
        flag = 1;
        deep[v] = deep[x]+1;
        a.push_back({deep[v], v}); cnt++;
        dfs(v, x);
        a.push_back({deep[x], x}); cnt++;
    }
    if(flag) {
        a.push_back({deep[x], x});
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>s;
    Fo(i,2,n) {
        LL x, y; cin>>x>>y;
        add(x, y);
        add(y, x);
    }
    cnt = 1;
    deep[s] = 1;
    a.push_back({1, s});
    dfs(s, s);
    Fo(i,1,cnt) {
        st[i][0] = a[i-1];
    }
    Fo(j,1,21) {
        Fo(i,1,cnt) {
            st[i][j] = calc(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    Fo(i,1,m) {
        LL a, b; cin>>a>>b;
        LL l=first[a], r=first[b];
        if(l>r) swap(l, r);
        LL k = LL(log(r-l+1)/log(2));
        cout<<calc(st[l][k], st[r-(1<<k)+1][k]).second<<endl;
    }
    return 0;
}
