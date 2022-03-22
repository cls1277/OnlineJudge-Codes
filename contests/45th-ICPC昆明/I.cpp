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

const LL maxn = 1e3+5;
struct Node {
    double x, y;
}e[maxn];
LL n, m, cnt[maxn];
struct Pair {
    double k;
    LL idx;
    bool operator < (const Pair &a) {
        if(a.k<0) return k<a.k;
        return k>a.k;
    }
};
vector<Pair>z1[maxn],z2[maxn];
double xs, ys, xt, yt;
double t1, t2, t3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    cin>>xs>>ys>>xt>>yt;
    t1 = atan((yt-ys)/(xt-xs));
    Fo(i,1,n) {
        cin>>e[i].x>>e[i].y;
        t2 = atan(e[i].y/e[i].x);
        t3 = t2-t1;
    }
    Fo(i,1,n)
        Fo(j,1,n) {
            if(i==j) continue;
            if(e[i].x==e[j].x) cnt[i]++;
            else {
                double k = (e[j].y-e[i].y)/(e[j].x-e[i].x);
                if(k>0) z1[i].push_back(Pair{k,j});
                else z2[i].push_back(Pair{k,j}); 
            }
        }
    Fo(i,1,n) {
        sort(z1[i].begin(),z1[i].end());
        sort(z2[i].begin(),z2[i].end());
    }
    Fo(i,1,m) {
        LL idx;
        LL x,y; cin>>x>>y;
        if(y<z2[x].size()) {
            idx = z2[x][y-1].idx;
        } else if(y<z2[x].size()+cnt[x]) {
            idx = -1;
        } else if(y<z2[x].size()+cnt[x]+z1[x].size()) {
            y -= z2[x].size()-cnt[x];
            idx = z1[x][y].idx;
        } else {
            Pair it = *z1[x].end();
            idx = it.idx;
        }
        if(idx==-1) {

        } else {

        }
    }
    return 0;
}