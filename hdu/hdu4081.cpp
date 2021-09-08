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

const LL maxn = 1005;
struct Node {
	int x , y , c;
};
Node a[maxn];
int T , n;
bitset<maxn>vis;
bitset<maxn>mst[maxn];
double mp[maxn][maxn] , ans , res; 

double dis(int b , int c) {
	return sqrt((a[b].x-a[c].x)*(a[b].x-a[c].x)+((a[b].y-a[c].y)*(a[b].y-a[c].y)));
}

void prim() {
	vis.reset();
	queue<int>q;
	vis[1]=1;
	q.push(1);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		double minn = INF; int tmp=-1;
		Fo(i,1,n) {
			if(i==u||vis[i]) continue;
			if(mp[u][i]<minn) {
				minn = mp[u][i];
				tmp = i;
			}
		}
		if(tmp==-1) break;
		vis[tmp]=1;
		q.push(tmp);
		mst[u][tmp]=mst[tmp][u]=1;
		ans+=minn;
	}
	return ;
}

double dfs(int x , int t , double maxx) {
	if(x==t) return maxx;
	Fo(i,1,n)
		if(!vis[i]&&mst[x][i]) {
			vis[i]=1;
			dfs(i,t,max(maxx,mp[x][i]));
			vis[i]=0;
		}
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	scanf("%d",&T);
	//cin>>T;
	while(T--) {
		scanf("%d",&n);
		//cin>>n;
		res=0; Ms(mst,0); ans=0;
		Fo(i,1,n) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);//cin>>a[i].x>>a[i].y>>a[i].c;
		Fo(i,1,n)
			Fo(j,i+1,n)
				mp[i][j]=mp[j][i]=dis(i,j);
		prim();
		vis.reset();
		Fo(i,1,n)
			Fo(j,i+1,n) {
				if(mst[i][j]) res=max(res,(a[i].c+a[j].c)/(ans-mp[i][j]));
				else {
					vis[i]=1;
					res=max(res,(a[i].c+a[j].c)/(ans-dfs(i,j,0)));	
				}
			}
		printf("%.2lf\n",res);
		//cout<<res<<endl;
	}
	return 0;
}

