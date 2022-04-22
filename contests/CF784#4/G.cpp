//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 55;
LL mp[maxn][maxn], ans[maxn][maxn];
LL a[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        Ms(a, 0); Ms(ans, 0); Ms(mp, 0);
        LL n, m; cin>>n>>m;
        Fo(i,1,n)
            Fo(j,1,m) {
                char ch; cin>>ch;
                if(ch=='.') mp[i][j]=1;
                else if(ch=='*') mp[i][j]=2;
                else {
                    mp[i][j] = 3;
                }
            }
        Fo(i,1,m) {
            LL cnt = 0;
            Fo(j,1,n) {
                if(mp[j][i]==2) cnt++;
                else if(mp[j][i]==3) {
                	a[j][i] = cnt;
                    cnt = 0;
                }
            }
            if(cnt) a[n][i] = cnt;
        }
        // Fo(i,1,n) {
        //     Fo(j,1,m) 
        //     cout<<a[i][j]<<' ';
        //     cout<<endl;
        // }
        // return 0;
        Fo(j,1,m) {
            Ro(i,n,1) {
                if(mp[i][j]==2&&!a[i][j]) {
                	ans[i][j] = 1;
                	continue;
				}
                ans[i][j] = mp[i][j];
                if(!a[i][j]) continue;
                LL k;
                if(mp[i][j]!=3) {
            		a[i][j]--;
            		ans[i][j] = 2;
            	}
                for(k=i-1; k>=1; k--) {
                    if(!a[i][j]) break;
                    ans[k][j] = 2;
                    a[i][j]--;
                }
                i=k+1;
            }
        }
        Fo(i,1,n) {
            Fo(j,1,m) {
            	if(ans[i][j]==1) cout<<'.';
            	else if(ans[i][j]==2) cout<<'*';
            	else cout<<'o';
			}
//                cout<<ans[i][j];
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}
