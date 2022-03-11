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

const LL maxn = 1e5+5;
LL n, a[maxn], fa[maxn], cnt, b[maxn];
vector<LL>c[maxn];

LL find(LL x) {
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=1; i<=n; i++) {
        fa[i] = i;
        cin>>a[i];
    }
    for(int i=1; i<=n; i++) {
        LL f1=find(a[i]), f2=find(a[a[i]]);
        if(f1!=f2)
            fa[f1] = f2;
    }
    for(int i=1; i<=n; i++) {
        LL f = find(i);
        if(i==f) {
            cnt++;
            b[i] = cnt;
        }
    }
    Fo(i,1,n) {
        LL f = find(i);
        c[b[f]].push_back(i);
    }
    LL maxx = 0, ans = 0;
    Fo(i,1,cnt) maxx=max(maxx , (LL)(c[i].size()));
    while(maxx!=1) {
        ans++;
        if(maxx%2) maxx = maxx/2+1;
        else maxx = maxx/2;
    }
    cout<<ans<<endl;
    Fo(i,1,ans) {
        vector<LL>d; bool vis[maxn]; Ms(vis,0);
        Fo(j,1,n) {
            if(a[j]==j) continue;
            if(vis[j]||vis[a[j]]) continue;
            vis[j] = vis[a[j]] = 1;
            d.push_back(j);
            d.push_back(a[j]);
            swap(a[j],a[a[j]]);
        }
        cout<<d.size()/2<<" ";
        for(auto &it:d)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}