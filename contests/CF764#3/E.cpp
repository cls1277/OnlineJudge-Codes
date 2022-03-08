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

const LL maxn = 15;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        tuple<LL,LL,LL> f2[maxn][maxn], f3[maxn][maxn][maxn];
        LL n,m; cin>>n>>m;
        Fo(i,1,n) {
            string s; cin>>s;
            Fo(j,0,m-1) {
                if(j+1<m) f2[s[j]-'0'][s[j+1]-'0'] = {j+1,j+2,i};
                if(j+2<m) f3[s[j]-'0'][s[j+1]-'0'][s[j+2]-'0'] = {j+1,j+3,i};
            }
        }
        string str; cin>>str;
        bool dp[1005]; Ms(dp,0);
        dp[0]=1;
        tuple<LL,LL,LL> a = make_tuple(0,0,0);
        Fo(i,0,m-1) {
            if(!dp[i]) continue;
            if(i+1<m && f2[str[i]-'0'][str[i+1]-'0']!=a) dp[i+2]=1;
            if(i+2<m && f3[str[i]-'0'][str[i+1]-'0'][str[i+2]-'0']!=a) dp[i+3]=1;
        }
        if(!dp[m]) {
            cout<<"-1"<<endl;
            continue;
        }
        vector<tuple<LL,LL,LL>>ans;
        LL i=m;
        while(i) {
            if(i>=1) {
                if(dp[i-2]&&f2[str[i-2]-'0'][str[i-1]-'0']!=a) {
                    ans.push_back(f2[str[i-2]-'0'][str[i-1]-'0']);
                    i-=2;
                } else {
                    ans.push_back(f3[str[i-3]-'0'][str[i-2]-'0'][str[i-1]-'0']);
                    i-=3;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto b:ans)
            cout<<get<0>(b)<<" "<<get<1>(b)<<" "<<get<2>(b)<<endl;
    }
    return 0;
}