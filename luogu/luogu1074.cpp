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

const LL maxm = 1e6+5;
int res[maxm] , ans=-INF;
const int e[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 6, 6, 7,  8,
                 8, 8, 8, 8, 7, 6, 6, 7, 8, 9, 9, 9, 8, 7, 6, 6, 7, 8, 9, 10, 9,
                 8, 7, 6, 6, 7, 8, 9, 9, 9, 8, 7, 6, 6, 7, 8, 8, 8, 8, 8, 7,  6,
                 6, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
struct DLX {
	static const int maxn = 1e6+5;
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
	void dance(int dep) {
		int i , j ,c=R[0];
		if(!R[0]) {
			//cout<<dep<<endl;
			int temp = 0;
			Fo(i,1,dep-1) {
				int x = (res[i] - 1) / 9 / 9 + 1;
		        int y = (res[i] - 1) / 9 % 9 + 1;
		        int v = (res[i] - 1) % 9 + 1;
		        temp += v*e[(x-1)*9+y-1];
				//cout<<v*e[(x-1)*9+y-1]<<endl;
			}
			//exit(0); 
			//cout<<temp<<endl;
			ans=max(ans,temp);
			return ;
		}
		IT(i,R,0) if(siz[i]<siz[c]) c=i;
		//cout<<c<<endl;
		remove(c);
		IT(i,D,c) {
			res[dep]=row[i];
			IT(j,R,i) remove(col[j]);
			dance(dep+1);
			IT(j,L,i) recover(col[j]);
		}
		recover(c);
		return;
	}
	#undef IT
}solver;

void Insert(int r , int c , int v) {
	int row = (r-1)*81+(c-1)*9+v;
	int dx = (r-1)/3+1 , dy = (c-1)/3+1;
	int b = (dx-1)*3+dy;
	int col1 = (r-1)*9+v;
	int col2 = 81+(c-1)*9+v;
	int col3 = 81*2+(b-1)*9+v;
	int col4 = 81*3+(r-1)*9+c;
	solver.insert(row,col1);
	solver.insert(row,col2);
	solver.insert(row,col3);
	solver.insert(row,col4);
	//cout<<row<<" "<<col1<<" "<<col2<<" "<<col3<<" "<<col4<<endl;
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	solver.init(729,324);
	Fo(i,1,9)
		Fo(j,1,9) {
			int x; cin>>x;
			if(x) Insert(i,j,x);//,cout<<i<<" "<<j<<" "<<x<<endl;
			else Fo(k,1,9) Insert(i,j,k);//,cout<<i<<" "<<j<<" "<<k<<endl;
		} 
	solver.dance(1);
	cout<<((ans==-INF)?(-1):ans);
	return 0;
}

