//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 205;
const LL mod = 1e9+7;
LL f[maxn][maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, m; cin>>n>>m;
        // string str; cin>>(str+1);
        char str[maxn]; cin>>(str+1);
        if(m&1) {
            cout<<0<<endl;
            continue;
        }
        Ms(f, 0);
        f[0][0][0] = 1;
        Fo(i,0,m-1) {
            Fo(j,0,i) { //left-right
                Fo(k,0,i) { //lcs
                	if(j) {
                		if(str[k+1]==')') f[i+1][j-1][k+1]=(f[i+1][j-1][k+1]+f[i][j][k])%mod;
                		else f[i+1][j-1][k] = (f[i+1][j-1][k]+f[i][j][k])%mod;
					}
					if(str[k+1]=='(') f[i+1][j+1][k+1] = (f[i+1][j+1][k+1]+f[i][j][k])%mod;
					else f[i+1][j+1][k] = (f[i+1][j+1][k]+f[i][j][k])%mod;
                }
            }
        }
        cout<<f[m][0][n]<<endl;
    }
    return 0;
}
