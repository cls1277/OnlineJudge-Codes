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

const LL maxn = 2e5+5;
LL n, m, fa[maxn];
pair<LL,LL>ti[maxn];
tuple<LL,LL,LL>a[maxn];

LL find(LL x) {
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>m;
        Fo(i,1,n) {
            fa[i] = i;
            LL x,y,z; cin>>x>>y>>z;
            ti[i] = {z,i};
            a[i] = {x,y,i};
        }
        Fo(k,0,1) {
            sort(a+1,a+n+1);
            Fo(i,2,n) {
                LL p1=get<0>(a[i]), q1=get<1>(a[i]);
                LL p2=get<0>(a[i-1]), q2=get<1>(a[i-1]);
                if(p1==p2&&q1-q2<=m) {
                    LL f1=find(get<2>(a[i])), f2=find(get<2>(a[i-1]));
                    if(f1!=f2) {
                        fa[f1] = f2;
                        ti[f2] = {min(ti[f1].first,ti[f2].first),i};
                    }
                }
            }
            Fo(i,1,n) swap(get<0>(a[i]), get<1>(a[i]));
        }
        LL cnt=0; vector<pair<LL,LL>>f; f.clear();
        Fo(i,1,n)
            if(fa[i]==i)
                f.push_back(make_pair(ti[i].first,i));
        // for(auto &it : f)
        //     cout<<it.first<<" "<<it.second<<endl;
        sort(f.begin(),f.end()); LL o = 1;
        Ro(i,f.size()-1,0) {
            LL tim = f[i].first;
            if(tim<=o) {
                cout<<o-1<<endl;
                break;
            }
            o++;
        }
    }
    return 0;
}