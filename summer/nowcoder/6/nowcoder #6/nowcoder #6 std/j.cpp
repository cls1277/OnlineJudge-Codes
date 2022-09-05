#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c,x;
		scanf("%d%d%d%d",&a,&b,&c,&x);
		int x1=x-c,x2=x-(b-c);
		int k=a-2*b;
		int flag=0;
		if(k) flag|=(x1%k==0) || (x2%k==0);
		else flag|=(x1==0) || (x2==0);
		puts(flag?"Yes":"No");
	}
	return 0;
}
