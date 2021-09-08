//By cls1277
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
#include<sstream>
#include<set>
#include<cassert>
#include<bitset>
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
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 15;
int n , m , P , K , a[maxn][maxn][maxn][maxn] , S;
bool vis[maxn][maxn][33000] , flag=false;
struct Node {
	int x , y , z , t;
	Node(){};
	Node(int xx , int yy , int zz , int tt) {
		x=xx , y=yy , z=zz , t=tt;
	}
};
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,1,-1};
vector<int>b[maxn][maxn];

void bfs() {
	queue<Node>q;
	q.push(Node(1,1,0,0));
	Ms(vis,0);
	vis[1][1][0] = 1;
	while(!q.empty()) {
		Node u=q.front(); q.pop();
		if(u.x==n&&u.y==m) {
			cout<<u.t;
			flag = true;
			return ;
		}
		Fo(i,0,3) {
			int vx=u.x+dx[i] , vy=u.y+dy[i] , vz=u.z , vt=u.t+1;
			if(b[vx][vy].size())
				for(int j=0; j<b[vx][vy].size(); j++)
					 vz=vz|(1<<(b[vx][vy][j]-1));
			if(vx<=0||vx>n||vy<=0||vy>m||vis[vx][vy][vz]) continue;
			if(a[u.x][u.y][vx][vy]&&(u.z&(1<<(a[u.x][u.y][vx][vy]-1)))==0) continue;
			if(a[u.x][u.y][vx][vy]==-1) continue;
			vis[vx][vy][vz] = 1;
			q.push(Node(vx,vy,vz,vt));
		}
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m>>P>>K;
	Fo(i,1,K) {
		int x , y , xx , yy , g;
		cin>>x>>y>>xx>>yy>>g;
		if(!g) g=-1;
		a[x][y][xx][yy]=a[xx][yy][x][y]=g;
	}
	cin>>S;
	Fo(i,1,S) {
		int x , y , g;
		cin>>x>>y>>g;
		b[x][y].push_back(g);
	}
	bfs();
	if(flag==false) cout<<"-1";
	return 0;
}

