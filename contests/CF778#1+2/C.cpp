//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = 2e5+5;
LL n, sum;
unordered_map<LL, LL>cnt;

bool dfs(LL s) {
    if(cnt[s]) {
        cnt[s]--;
        return true;
    }
    if(s==1) return false;
    LL a=s/2, b=s-a;
    if(dfs(a)) return dfs(b);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        cnt.clear();
        sum = 0;
        Fo(i,1,n) {
            LL x; cin>>x;
            sum+=x; cnt[x]++;
        }
        if(dfs(sum)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}