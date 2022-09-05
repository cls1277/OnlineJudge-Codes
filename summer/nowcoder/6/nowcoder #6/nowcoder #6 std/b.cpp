#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef long long ll;

const int N=2e6+5;
int n,m,d[N],st[N],top,c[N];
vector<int> ve[N];

void dfs(int x,int fa)
{
	st[++top]=x;
	c[x]++,c[st[top-min(top,d[x]+1)]]--;
	for(int v:ve[x]) if(v!=fa) dfs(v,x);
	top--;
}

void dfss(int x,int fa)
{
	for(int v:ve[x]) if(v!=fa) 
	{
		dfss(v,x),c[x]+=c[v];
	}
}

int main()
{
	cin>>n;assert(1<=n&&n<=2000000);
	for(int i=1,x,y;i<n;i++) 
	{
		cin>>x>>y;assert(1<=x&&x<=n);assert(1<=y&&y<=n);
		ve[x].pb(y),ve[y].pb(x);
	}
	for(int i=1;i<=n;i++){cin>>d[i];assert(0<=d[i]&&d[i]<=n);}
	dfs(1,0);
	dfss(1,0);
	for(int i=1;i<=n;i++) cout<<c[i]<<' ';
}

