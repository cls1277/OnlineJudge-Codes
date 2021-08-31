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
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 1e5+5;
int ans,res[maxn];
struct DLX {
	static const int maxn = 1e5+5;
	#define IT(i,A,x) for(i=A[x]; i!=x; i=A[i])
	int n , m , tot;
	int first[maxn] , siz[maxn];
	int L[maxn] , R[maxn] , U[maxn] , D[maxn];
	int col[maxn] , row[maxn];
	void init(int _n , int _m) {
		n=_n , m=_m;
		Fo(i,0,_m) {
			L[i]=i-1; R[i]=i+1;
			U[i]=D[i]=i;
		}
		L[0]=_m; R[_m]=0; tot=_m;
		Ms(first , 0);
		Ms(siz , 0);
	}
	void insert(const int &r , const int &c) {
		col[++tot]=c , row[tot]=r , siz[c]++;
		D[tot]=D[c] , U[D[c]]=tot , U[tot]=c , D[c]=tot;
		if(!first[r])
			first[r]=L[tot]=R[tot]=tot;
		else {
			R[tot]=R[first[r]] , L[R[first[r]]]=tot;
			L[tot]=first[r] , R[first[r]]=tot;
		}
	}
	void remove(const int &c) {
		int i , j;
		L[R[c]]=L[c] , R[L[c]]=R[c];
		IT(i,D,c)
			IT(j,R,i)
				U[D[j]]=U[j] , D[U[j]]=D[j] , siz[col[j]]--;
	}
	void recover(const int &c) {
		int i , j;
		IT(i,U,c)
			IT(j,L,i)
				U[D[j]]=D[U[j]]=j , siz[col[j]]++;
		L[R[c]]=R[L[c]]=c;
	}
	bool dance(int dep) {
		int i , j ,c=R[0];
		if(!R[0]) {
			ans=dep;
			return 1;
		}
		IT(i,R,0) if(siz[i]<siz[c]) c=i;
		remove(c);
		IT(i,D,c) {
			res[dep]=row[i];
			IT(j,R,i) remove(col[j]);
			if(dance(dep+1)) return 1;
			IT(j,L,i) recover(col[j]);
		}
		recover(c);
		return 0;
	}
	#undef IT
}solver;
int n , m;

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	solver.init(n,m);
	Fo(i,1,n) Fo(j,1,m) {
		int x;
		cin>>x;
		if(x) solver.insert(i,j);
	}
	solver.dance(1);
	if(ans)
		Fo(i,1,ans-1)
			cout<<res[i]<<" ";
	else cout<<"No Solution!";
	return 0;
}
