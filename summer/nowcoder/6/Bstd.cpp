//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'
#define maxn 2000005
#define ll long long
#define int long long
#define res register int
struct Node{
	int to,next;
};
Node edge[maxn<<2]; //链式前向星要多开几倍数组
int head[maxn<<2],power[maxn],n,m,d[maxn],fa[maxn][30],ans,num;

inline int read(){ //快读
	int s=0;
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') s=s*10+c-'0',c=getchar();
	return s;
}
//链式前向星
inline void add(int x,int y){edge[++num].to=y,edge[num].next=head[x],head[x]=num;}
//接下来是初始化
inline void work(int u,int fath){
	d[u]=d[fath]+1,fa[u][0]=fath;
	for (res i=0;fa[u][i];++i) fa[u][i+1]=fa[fa[u][i]][i];
	for (res i=head[u];i;i=edge[i].next){
		int e=edge[i].to;
		if (e!=fath) work(e,u);
	}
}
//倍增求LCA
inline int Lca(int u,int v){
	if (d[u]>d[v]) swap(u,v);
	for (res i=21;i>=0;--i) if (d[u]<=d[v]-(1<<i)) v=fa[v][i];
	if (u==v) return u;
	for (res i=21;i>=0;--i) if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

//累计
inline void Get(int u,int fath){
	for (res i=head[u];i;i=edge[i].next){
		int e=edge[i].to;
		if (e==fath) continue;
		Get(e,u);
		power[u]+=power[e];
	}
}

LL findFa(LL x, LL y) {
    Ro(i,21,0) {
        if(d[fa[x][i]]>=y)
            x = fa[x][i];
        if(d[x]==y) return x;
    }
    return 1;
}

signed main(){
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif
	n=read();
	int x,y;
	for (res i=1;i<n;++i){
		x=read(),y=read();
		add(x,y); add(y,x);
	}
    d[0]=-1;
	work(1,0);
    for (res i=1;i<=n; ++i) {
        x=read();
        if(d[i]<=x) {
            int lca=Lca(i,1);
            ++power[i];++power[1];--power[lca];--power[fa[lca][0]];            
        } else {
            y=findFa(i, d[i]-x);
            int lca=Lca(i,y);
		    ++power[i];++power[y];--power[lca];--power[fa[lca][0]];   
        }
    }
	Get(1,0);
    Fo(i,1,n)  printf("%lld ",power[i]);
    //cout<<power[i]<<' ';
	return 0;
}