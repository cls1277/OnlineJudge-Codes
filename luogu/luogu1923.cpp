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
#define Fo(i,a,b) for(int i=(a); i<=(b); i++)
#define Ro(i,b,a) for(int i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 5e6+5;
const LL maxm = 10;
int n , K , id[maxn] , rk[maxn] , sum[10] , minn=INF;
struct Node {
	int key[maxm];
	void print() {
		int pos=1;
		while(pos<=maxm&&!key[pos]) pos++;
		Fo(i,pos,maxm) printf("%d",key[i]);//cout<<key[i];
		printf(" "); //cout<<" ";
		return ;
	}
};
Node a[maxn];

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	n=read(); K=read();
	//cin>>n>>K;
	Fo(i,1,n) {
		int x; x=read();//cin>>x;
		Ro(j,maxm,1) {
			a[i].key[j]=x%10;
			x/=10;
			if(!x) {
				minn=min(minn,j);
				break;
			}
		}
		id[i] = i;
	}
	int *b=id , *c=rk;
	Ro(i,maxm,minn) {
		Ms(sum,0);
		Fo(j,1,n) sum[a[j].key[i]]++;
		Fo(j,1,9) sum[j]+=sum[j-1];
		Ro(j,n,1) c[sum[a[b[j]].key[i]]--]=b[j];
		Fo(j,1,n) b[c[j]]=j;
		swap(b,c);
	}
	a[b[K+1]].print();
	//Fo(i,1,n) a[b[i]].print();
	return 0;
}

