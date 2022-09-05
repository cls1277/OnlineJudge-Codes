//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;
LL n, ans = INT_MAX;

void dfs(LL A, LL idx, LL res) {
//	cout<<A<<' ';
    if(idx==n+1) {
        ans = min(ans, res);
        return ;
    }
    if(res>=ans) return ;
    if(A%n==idx) dfs(A, idx+1, res);
    else {
        Fo(i,0,9) {
            LL B = A*10+i;
            if(B%n!=idx%n) continue;
			dfs(B, idx+1, res+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    dfs(0, 1, 0);
    cout<<ans;
    return 0;
}
