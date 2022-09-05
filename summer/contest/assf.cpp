#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct lr{int l,r,w;}a[500000];
int f[500000],g[500000],n,m,R;
int cmp(const lr &a,const lr &b)
{
	return a.r<b.r;
}
int main()
{
//	freopen("data.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&R);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w),a[i].r+=R;
	sort(a+1,a+m+1,cmp);
	a[0].r=-1;
	for(int i=1;i<=m;i++)
	{
		int l=0,r=i-1,mid;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(a[mid].r<=a[i].l)l=mid;
			else r=mid-1;
		}
		if(a[r].r<=a[i].l)f[i]=g[r]+a[i].w;
		else f[i]=a[i].w;
		g[i]=max(g[i-1],f[i]);
	}
	cout<<g[m]<<endl;
}
