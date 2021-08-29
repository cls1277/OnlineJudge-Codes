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
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 30;
string M , k;
int ops;
int D[maxn][maxn];

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>k>>M;
	for(char c='A'; c<='Z'; c++) {
		int num=0; char p=c;
		for(int i=0; i<=25; i++) {
			if(p>'Z') p='A';
			D[c-'A'][p-'A']/*=D[p-'A'][c-'A']*/=num++;
			p++; 
		}
	}
	/*Fo(i,0,25) {
		Fo(j,0,25)
			cout<<D[i][j]<<" ";
		cout<<endl;
	}*/
	Fo(i,0,k.length()-1) {
		char tmp=k[i];
		if(tmp>='a'&&tmp<='z')
			tmp = tmp-'a'+'A';
		k[i] = tmp;
	}
	Fo(i,0,M.length()-1) {
		char tmp=M[i] , temp;
		bool flag = false;
		if(tmp>='A'&&tmp<='Z') {
			flag = true;
			temp = tmp;
		}
		if(tmp>='a'&&tmp<='z')
			temp = tmp-'a'+'A';
		
		if(flag) printf("%c",D[k[ops]-'A'][temp-'A']+'A');
		else printf("%c",D[k[ops]-'A'][temp-'A']+'a');
		ops++;
		if(ops==k.length()) ops=0;
	}
	return 0;
}

