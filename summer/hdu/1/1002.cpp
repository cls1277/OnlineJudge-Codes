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
// pair<bool, bool> vis[20][20];
bool vis[20][20], mp[20][20];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
struct Node {
    LL a, b, c, d;
};

struct Que {
	pair<LL, LL> p;
	LL idx;
};

LL count(LL x) {
    LL cnt = 0;
    while(x) {
        if(x%2==0) cnt++;
        x >>= 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, m, K; cin>>n>>m>>K;
        vector<Node> e(K+1);
        vector<LL> f;
        LL xs, ys, xt, yt; cin>>xs>>ys>>xt>>yt;
        Fo(i,1,K) {
            LL a, b, c, d; cin>>a>>b>>c>>d;
            if(a>c) swap(a, c);
            if(b>d) swap(b, d);
            if(!b) f.push_back(i);
            e[i] = {a, b, c, d};
        }
        LL len = (1<<K)-1;
        bool ccc = 0;
        Ro(k,len,0) {
//		Fo(k,0,len) {
            bool flag = 0;
            for(auto it:f)
                if(((k>>(it-1))&1)) {
                    flag = 1;
                    break;
                }
            if(!flag) continue;
            Fo(i,0,n) Fo(j,0,m) vis[i][j] = mp[i][j] = 0;
            Fo(i,1,K) {
                if(!((k>>(i-1))&1)) continue;
                LL a=e[i].a, b=e[i].b, c=e[i].c, d=e[i].d;
                if(a==c) {
                    if(b>d) swap(b, d);
                    Fo(j,b,d-1) mp[a][j] = 1;
                } else {
                    if(a>c) swap(a, c);
                    Fo(j,a,c-1) mp[j][b] = 1;
                }
            }
            queue<Que> q;
            for(auto it:f) {
                if((k>>(it-1))&1) {
                    q.push({{e[it].a, e[it].b}, (e[it].b==e[it].d)});
                    vis[e[it].a][e[it].b] = 1;
                }
            }
            flag = 0;
            bool p1=0, p2=0, p3=0, p4=0;
            while(!q.empty()) {
                Que u = q.front(); q.pop();
                if((u.idx==0&&u.p.second==m-1)||(u.idx==1&&(u.p.first==0||u.p.first==n-1))) {
                    flag = 1;
                    break;
                }
                if(u.p.second==ys) p1 = (u.p.first>xs);
                if(u.p.second==yt) p2 = (u.p.first>xt);
                if(u.p.first==xs) p3 = (u.p.second>ys);
                if(u.p.first==xt) p4 = (u.p.second>yt);
                Fo(i,0,3) {
                    LL tx=u.p.first+dx[i], ty=u.p.second+dy[i];
                    if(tx<0||ty<0||tx>n||!mp[tx][ty]||vis[tx][ty]) continue;
                    q.push({{tx, ty}, u.p.second==ty});
                    vis[tx][ty] = 1;
                }
            }
            if(flag&&(p1!=p2||p3!=p4)) {
//            	cout<<count(k)+1<<endl;
//				cout<<__builtin_popcount(k)-1<<endl;
//				ccc = 1;
//            	break;
				continue;
			} else {
				ccc = 1;
				cout<<K-__builtin_popcount(k)<<endl;
				break; 
			}
        }
        if(!ccc) cout<<K<<endl;
    }
    return 0;
}
