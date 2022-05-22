//By cls1277
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
#include<set>
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

const LL maxn = 2e5+5;
LL a[maxn];

LL solve(LL x) {
    if(x<=2) return 0;
    if(x==3) return 1;
    x-=2;
    LL res = 0;
    while(x>1) {
        res += x/2;
        if(x%2) x=x/2+1;
        else x=x/2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        vector<pair<LL, LL>>v;
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) {
            if(i+1<=n&&a[i+1]==a[i]) {
                bool flag = 1;
                Fo(j,i+1,n) {
                    if(a[j]!=a[i]) {
                        v.push_back({i, j-1});
                        i = j-1;
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    v.push_back({i, n});
                    break;
                }
            }
        }
        if(!v.size()) {
            cout<<'0'<<endl;
            continue;
        }
        LL ans = 0;
        if(v.size()==1) {
            cout<<solve(v[0].second-v[0].first+1)<<endl;
            continue;
        }
        cout<<v[v.size()-1].second-v[0].first-2<<endl;
        // for(auto it:v) ans+=solve(it.second-it.first+1);
        // LL r = v[0].second, l=v[v.size()-1].first;
        // ans += l-r;
        // cout<<ans<<endl;
    }
    return 0;
}