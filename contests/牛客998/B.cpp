//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 30;
int n, m, nums[maxn];
void dfs(int x, int idx, int nums[]) {
    if(x==n+1) {
        if(idx==m) {
            for(int i=1; i<=idx; i++) cout<<nums[i]<<' ';
            cout<<endl;
            // return ;
        }
        return ;
    }
    nums[++idx] = x;
    dfs(x+1, idx, nums);
    idx--;
    dfs(x+1, idx, nums);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    dfs(1, 0, nums);
    return 0;
}