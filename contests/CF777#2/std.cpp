#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
#include<queue>
#define clean(x) memset(x,0,sizeof(x))
#define maxn 100005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}
int n,aa,cnt,maxa,step;
int de[maxn],f[maxn][35],to[maxn],vis[maxn],p[maxn];
set<int>s;
int main()
{
    freopen("data.txt","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		de[aa]++;
		f[i][0]=aa;
	}
	for(int i=1;i<=30;i++){
		for(int j=1;j<=n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
	for(int i=1;i<=n;i++){
		if(de[i]==0) cnt++;
	}
	for(int i=1;i<=n;i++){
		aa=read();p[i]=aa;
		if(aa<=n) vis[aa]=1;
		maxa=max(maxa,aa);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) s.insert(i);
		vis[i]=0;
	}
	for(int i=1; i<=n; i++)
		cout<<p[i]<<" ";
	cout<<endl<<"!!!!"<<endl;
    // for(auto &it:s) cout<<it<<" ";
    // cout<<"---"<<endl;//比n大的数的位置放进s
	step=(maxa-n)/cnt;
	for(int i=1;i<=n;i++){
		int x=i;
		for(int j=0;j<=30;j++){
			if(step&(1<<j))
			x=f[x][j];
		}
		cout<<x<<" ";
		if(!vis[p[x]]){
			// printf("%d\n",p[x]);
			vis[p[x]]=1;
		}else{
			int y=*s.lower_bound(p[x]);
			s.erase(y);
			// cout<<y<<" ";
			// printf("#%d-%d-%d\n",x,y,p[x]);
		}
        // for(auto &it:s) cout<<it<<" ";
        cout<<endl;
	}
	return 0;
}
