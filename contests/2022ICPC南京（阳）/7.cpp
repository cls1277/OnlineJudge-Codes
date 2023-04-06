#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int a[maxn], b[maxn];

int gcd(int x, int y) {
	return y?gcd(y, x%y):x;
}

int main() {
//	freopen("data.txt","r",stdin);
	int T; scanf("%d",&T);
	while(T--) {
		int n; scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			if(a[i]!=0) b[i] = a[i];
			else b[i] = 1;
		}
		int sum = 1, tot = 1;
		bool flag = 0;
		for(int i=1; i<=n; i++) {
			sum += b[i];
			if(b[i]!=-1) tot++;
			if(sum<=0) {
				flag = 1;
				break;
			}
		}
		if(flag) {
			printf("-1\n");
			continue;
		}
		int op = 0; 
		for(int i=n; i>=1; i--) {
			if(!a[i]&&sum-2+op>0) {
				b[i] = -1;
				sum -= 2;
				tot --;
			}
			if(b[i]==1) {
				sum --;
				tot --;
			}
			if(b[i]==-1) {
				sum ++;
			}
			op += b[i];
		}
		sum = tot = 1;
		for(int i=1; i<=n; i++) {
			sum += b[i];
			if(b[i]!=-1) tot++;
		}
		int g = gcd(tot, sum);
		printf("%d %d\n",tot/g, sum/g);
	}
    return 0;
}
