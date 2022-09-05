#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=300005;
struct shu
{
    int x,y;
    long long w;
    friend bool operator <(shu a,shu b)
    {
        return a.y<b.y;
    }
}a[maxn];
int b[maxn];
map<int,int>mp;
map<int,int>::iterator it;

long long n=0,m,d[maxn*2]={0};

int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch<='9'&&ch>='0')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
void init()
{
    m=read();
    for(int i=1;i<=m;i++)
    {
        a[i].x=read();
        b[i] = a[i].x;
//        a[i].y=read();
        a[i].y = i+a[i].x-1;
        a[i].x = max(0, i-a[i].x+1);
//        a[i].w=read();
		
        mp[a[i].x]=1;
        mp[a[i].y]=1;
    }
    for(int i=1; i<=m; i++) {
    	a[i].w=read();
    	a[i].w *= b[i];
	}
    for(it=mp.begin();it!=mp.end();it++)
    it->second=++n;
    for(int i=1;i<=m;i++)
    {
        a[i].x=mp[a[i].x];
        a[i].y=mp[a[i].y];
    }
    sort(a+1,a+1+m);
}


int main()
{
    freopen("data.txt","r",stdin);
    init();
    int k=1;
    for(int i=1;i<=n;i++)
    {
        d[i]=d[i-1];
        while(i==a[k].y&&k<=m)
        {
            d[i]=max(d[i],d[a[k].x]+a[k].w);
            k++;
        }
    }
    cout<<d[n];
    return 0;
}
