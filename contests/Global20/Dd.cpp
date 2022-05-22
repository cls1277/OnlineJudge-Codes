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
LL n, a[maxn], b[maxn], ans;

bool judge(LL c[]) {
    Fo(i,1,n)
        if(a[i]!=c[i])
            return 0;
    return 1;
}

void dfs(LL c[]) {
    if(ans) return ;
    if(judge(c)) {
        ans = 1;
        return ;
    }
    Ro(i,n,3) {
        if(c[i]==c[i-1]) {
            Ro(j,i-2,1) {
                Fo(k,j+1,i) c[k]=c[k-1];
                c[j] = c[i];
                dfs(c);
                Fo(k,j,i-1) c[k]=c[k+1];
                c[i] = c[i-1];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        ans = 0;
        cin>>n;
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) cin>>b[i];
        dfs(b);
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}