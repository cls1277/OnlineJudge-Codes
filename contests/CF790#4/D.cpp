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
int a[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vector<int> s1(n+m, 0), s2(n+m, 0);
        Fo(i,0,n-1) {
            Fo(j,0,m-1) {
                cin>>a[i][j];
            }
        }
        Fo(i,0,n-1) {
            Fo(j,0,m-1) {
                s1[i+j] += a[i][j];
                s2[i-j+m] += a[i][j];
            }
        }
        int ans = 0;
        Fo(i,0,n-1) {
            Fo(j,0,m-1) {
                ans = max(ans, s1[i+j]+s2[i-j+m]-a[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}