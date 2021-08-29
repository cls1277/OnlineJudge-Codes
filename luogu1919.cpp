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

const LL maxn = (1<<21)+100;
struct Complex {
	double x , y;
	Complex(double xx=0 , double yy=0) {
		x=xx , y=yy;
	}
	Complex operator + (Complex a) {
		return Complex(x+a.x,y+a.y);
	}
	Complex operator - (Complex a) {
		return Complex(x-a.x,y-a.y);
	}
	Complex operator * (Complex a) {
		return Complex(x*a.x-y*a.y,x*a.y+y*a.x);
	}
}; 
Complex a[maxn] , b[maxn];
int n , m , lim , l , r[maxn] , ans[maxn]; 
char str1[maxn] , str2[maxn];

void fft(Complex *A , int type) {
	Fo(i,0,lim-1)
		if(i<r[i])
			swap(A[i],A[r[i]]);
	for(int mid=1; mid<lim; mid<<=1) {
		Complex wn(cos(PI/mid),type*sin(PI/mid));
		for(int R=mid<<1,j=0; j<lim; j+=R) {
			Complex w(1,0);
			for(int k=0; k<mid; k++,w=w*wn) {
				Complex x=A[j+k] , y=w*A[j+mid+k];
				A[j+k]=x+y; A[j+mid+k]=x-y;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	scanf("%s%s",str1,str2);
	n=strlen(str1); m=strlen(str2);
	Ro(i,n-1,0) a[n-1-i].x=str1[i]-'0';
	Ro(i,m-1,0) b[m-1-i].x=str2[i]-'0';
	lim=1; while(lim<=n+m) lim<<=1,l++;
	Fo(i,0,lim-1) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1)); 
	fft(a,1);
	fft(b,1);
	Fo(i,0,lim) a[i]=a[i]*b[i];
	fft(a,-1);
	Fo(i,0,lim) {
		ans[i] += (int)(a[i].x/lim+0.5);
		if(ans[i]>=10) {
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	lim++;
	while(lim>=0&&!ans[lim]) lim--;
	Ro(i,lim,0) cout<<ans[i];
	return 0;
}

