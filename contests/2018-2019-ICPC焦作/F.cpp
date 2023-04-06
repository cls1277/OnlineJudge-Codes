//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e3+5;
char mp[4*maxn][6*maxn];
int dx[5] = {0, 2, 2, 4, 4};
int dy[5] = {4, -2, 6, 0, 4};
int a[6][4*maxn][6*maxn], idx;
pair<LL, LL> b[maxn*maxn];
LL dis[maxn*maxn], s, t;

struct Edge {
    LL to , next , len;
}e[maxn*maxn*6];

LL tot, head[maxn*maxn];

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}
struct Que {
	LL len , num;
};

bool operator < (Que a , Que b) {
	return a.len > b.len;
}

void dij(LL s) {
    for(int i=1; i<=idx; i++) dis[i]=INT_MAX;
	dis[s] = 0;
	priority_queue<Que>q;
	q.push({0,s});
	while(!q.empty()) {
		Que u=q.top();
		q.pop();
		if(u.len!=dis[u.num]) continue;
		for(int i=head[u.num]; i;i=e[i].next) {
			LL v=e[i].to;
			if(dis[v]>dis[u.num]+e[i].len) {
				dis[v] = dis[u.num]+e[i].len;
				q.push({dis[v], v});
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
    LL T; cin>>T;
    while(T--) {
        idx = 0; tot = 0;
        LL r, c; cin>>r>>c;
        Fo(i,0,5)
            Fo(j,1,4*r+3)
                Fo(k,1,6*c+3)
                    a[i][j][k] = 0;
        string str; getline(cin, str);
        Fo(i,1,4*r+3) {
            getline(cin, str);
            // cout<<str<<endl;   
            for(int j=0; j<str.length(); j++) {
                mp[i][j+1] = str[j];
            } 
        }
        Fo(i,1,4*r+3) {
            Fo(j,1,6*c+3) {
                if(mp[i][j]=='S') {
                    s = a[0][i-2][j-2];
                }
                if(mp[i][j]=='T') {
                    t = a[0][i-2][j-2];
                }
                if(mp[i][j]=='+') {
                    // cout<<i<<' '<<j<<endl;
                    bool flag = 1;
                    Fo(k,0,4) {
                        if(mp[i+dx[k]][j+dy[k]]!='+') {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) {
                        idx++;
                        b[idx] = {i, j};
                        a[0][i][j] = idx;
                        Fo(k,0,4) a[k+1][i+dx[k]][j+dy[k]] = idx;
                    }
                }
            }
        }
        // cout<<s<<' '<<t;
        // Fo(i,0,5) {
        //     cout<<i<<":\n";
        //     Fo(j,1,4*r+3) {
        //         Fo(k,1,6*c+3) {
        //             if(a[i][j][k]) {
        //                 cout<<j<<' '<<k<<' '<<a[i][j][k]<<endl;
        //             }
        //         }
        //     }
        // }
        Fo(i,1,idx) {
            LL ux=b[i].first, uy=b[i].second;
            if(uy+3<=6*c+3&&(mp[ux][uy+1]==' '||mp[ux][uy+2]==' '||mp[ux][uy+3]==' ')) {
                add(a[0][ux][uy], a[4][ux][uy], 1);
            }
            if(ux+1<=4*r+3&&uy-1>=1&&mp[ux+1][uy-1]==' ') {
                add(a[0][ux][uy], a[3][ux][uy], 1);
            }
            if(ux+1<=4*r+3&&uy+5<=6*c+3&&mp[ux+1][uy+5]==' ') {
                add(a[0][ux][uy], a[2][ux][uy+4], 1);
            }
            if(ux+3<=4*r+3&&uy-1>=1&&mp[ux+3][uy-1]==' ') {
                add(a[0][ux][uy], a[1][ux+2][uy-2], 1);
            }
            if(ux+3<=4*r+3&&uy+5<=6*c+3&&mp[ux+3][uy+5]==' ') {
                add(a[0][ux][uy], a[0][ux+2][uy+6], 1);
            }
            if(ux+4<=4*r+3&&uy+3<=6*c+3&&(mp[ux+4][uy+1]==' '||mp[ux+4][uy+2]==' '||mp[ux+4][uy+3]==' ')) {
                add(a[0][ux][uy], a[0][ux+4][uy], 1);
            }
        }
        // Fo(i,1,idx) {
        //     cout<<i<<":\n";
        //     Eo(j,i,e) {
        //         cout<<e[j].to<<' ';
        //     }
        //     cout<<endl;
        // }
        dij(s);
        if(dis[t]==INT_MAX) cout<<-1<<endl;
        else cout<<dis[t]+1<<endl;
        Fo(i,1,idx) head[i] = 0;
    }
    return 0;
}