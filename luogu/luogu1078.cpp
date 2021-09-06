//copy
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define N 1001
int n,k,m,s,t;//如题
int a[101][101],wen[101];//wen该城市文化，a用来读入矩阵
int d[100001];//单源最短路
bool vis[100001];//是否访问过 最短路中用
int qi,mo,f;//中间用来输入的
inline int read()//读入优化不多说了
{
    char ch=getchar();
    int x=0,f=1;
    while((ch>'9'||ch<'0')&&ch!='-')
        ch=getchar();
    if(ch=='-')
    {
        f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
struct Edge
{
    int v,w;
    Edge(int _v=0,int _w=0){v=_v,w=_w;}
};
vector<Edge>e[N];//vector存邻接表
vector<int>di[N];//用vector存每个国家的文化和那些国家相对
struct Node
{
    int v,w;
    Node(int _v=0,int _w=0){v=_v,w=_w;}
    bool operator <(const Node &n) const
    {
        return w>n.w;
    }
};
priority_queue<Node>q;//堆优化最短路
int x;
bool kx(int x,int y)//判断下个国家能否走
{
    for(int j=0;j<di[y].size();j++)
     {
     	if(di[y][j]==x)return false;
     }
     return true;
}
void dijkstra()//最短路模板
{
    d[s]=0;
    q.push(Node(1,0));
    while(!q.empty())
       {
       	int x=q.top().v;
       	q.pop();
       	if(vis[x])continue;
       	vis[x]=true;
       	for(int i=0;i<e[x].size();i++)
       	  {
       	  	int v=e[x][i].v;
       	  	int w=e[x][i].w;
       	  	if(kx(wen[x],wen[v]))//判断能否走
       	  	{
       	  	    if(d[v]>d[x]+w)
       	  	      {
       	  	 	  d[v]=d[x]+w;
       	  	 	  q.push(Node(v,d[v]));
                  }
            }
            else
       	  	 continue;
          }
       }
}
int main()
{
	freopen("data.txt","r",stdin); 
    n=read();
    k=read();
    m=read();
    s=read();
    t=read();	
    for(int i=1;i<=n;i++)
    wen[i]=read();
    for(int i=1;i<=k;i++)
      for(int j=1;j<=k;j++)
      {
      	x=read();
      	if(x==1)di[i].push_back(j);
      	a[i][j]=x;
      }
    for(int j=1;j<=m;j++)
       {
       	cin>>qi>>mo>>f;
       	if(a[mo][qi]==0)//如果不敌对再加边
           e[qi].push_back(Edge(mo,f));
       	if(a[qi][mo]==0)
           e[mo].push_back(Edge(qi,f));
       }
    memset(d,0x3f3f3f3f,sizeof(d));
    dijkstra();
    if(vis[t]&&wen[t]!=wen[s])cout<<d[t];
    else cout<<"-1";
    return 0;
}
