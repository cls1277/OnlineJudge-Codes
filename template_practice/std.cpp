#include<bits/stdc++.h>

#define INL inline
#define ll long long 

using namespace std;

const int N=605;

int n,a[N][N],MOD;

INL int read()
{
	int x=0,w=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*w;
}

INL int sol()
{
	int res=1,w=1;
	for(int i=1;i<=n;i++)
	{ 
		for(int j=i+1;j<=n;++j)
		{
    		while(a[i][i])
			{
     	    	int div=a[j][i]/a[i][i];
        		for(int k=i;k<=n;++k)
				{
        		    a[j][k]=(a[j][k]-1ll*div*a[i][k]%MOD+MOD)%MOD;
        		}
        		swap(a[i],a[j]);w=-w;
    		}//对第 i 行和第 j 行做辗转相减。	
    		swap(a[i],a[j]);w=-w;
		}
	}
	for(int i=1;i<=n;i++)res=1ll*a[i][i]*res%MOD;
	res=1ll*w*res;
	return (res+MOD)%MOD;//经 典 模 加 模
}

int main()
{
	#ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
	n=read(),MOD=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	int ans=sol();printf("%d\n",ans);
	return 0;
}
