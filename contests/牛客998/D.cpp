//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 6;
int a[maxn][maxn], c[maxn][maxn], ans = INT_MAX;

void turn(int x, int y) {
    int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
    Fo(i,0,4) {
        int tx=x+dx[i], ty=y+dy[i];
        if(tx>0&&tx<6&&ty>0&&ty<6) {
          a[tx][ty] = 1-a[tx][ty];      	
		}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int T; cin>>T;
    while(T--) {
        ans = INT_MAX;
        Fo(i,1,5) {
            string str; cin>>str;
            Fo(j,1,5) {
                a[i][j] = str[j-1]-'0';
                c[i][j] = a[i][j];
            }
        }
        Fo(i,0,31) {
            Fo(j,1,5) {
                Fo(k,1,5) {
                    a[j][k] = c[j][k];
                }
            }
            int b[maxn], cnt = 0;
            Fo(j,0,4) {
                b[j+1] = (i>>j)&1;
                // 1按 0不按
                if(b[j+1]) {
                    cnt++;
                    turn(1, j+1);
                }
            }
            if(cnt > 6) continue;
            bool flag = 0;
            Fo(j,1,4) {
                Fo(k,1,5) {
                    if(!a[j][k]) {
                        cnt++;
                        if(cnt>6) {
                            flag = 1;
                            break;
                        }
                        turn(j+1, k);
                    }
                }
                if(flag) break;
            }
            Fo(j,1,5) {
                if(!a[5][j]) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) ans = min(ans, cnt);
        }
        if(ans==INT_MAX) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
