//By cls1277
#include<bits/stdc++.h>
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
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

// const LL maxn = ;

LL f(LL x , LL c , LL mod) {
    return (x*x%mod+c)%mod;
}

LL gcd(LL x , LL y) {
    return (y==0)?x:gcd(y,x%y);
}

LL pollard_rho(LL x) {
    LL c = rand()%(x-1)+1;
    LL t=f(0,c,x) , r=f(f(0,c,x),c,x);
    while(t!=r) {
        LL g = gcd(abs(t-r),x);
        if(g>1) return g;
        t=f(t,c,x);
        r=f(f(r,c,x),c,x);
    }
    return x;
}

inline LL rho1(LL n){
    LL x,y,c,g, i,j;
    x=y=rand(); c=rand();//初始化
    i=0,j=1;//倍增初始化
    while(++i){
		x=f(x,c,n);
        cout<<"x:"<<x<<" y:"<<y<<endl;
		if(x==y)break;//跑完了一个环
        g=gcd(abs(y-x),n);//求gcd（注意绝对值）
   		if(g>1)return g;
		if(i==j)y=x,j<<=1;//倍增的实现
	}
}

LL rho(LL n) {
    LL x,y,z,i,j,c;
    while(1) {
        x=y=rand()%n;
        c=rand()%n;
        z=1; i=0; j=1;
        while(++i) {
            x=f(x,c,n);
            z=abs(y-x)*z%n;
            if(!z||x==y) break;
            if(i==j||i%127==0) {
                LL g=gcd(z,n);
                if(g>1) return g;
                if(i==j) {
                    j<<=1;
                    y=x;
                }
            }
        }
    }
}

// inline LL rho(LL p){//求出p的非平凡因子
//     LL x,y,z,c,g, i,j;//先摆出来（z用来存（y-x）的乘积）
//     while(1){//保证一定求出一个因子来
//         y=x=rand()%p;//随机初始化
//         z=1; c=rand()%p;//初始化
//         i=0,j=1;//倍增初始化
//         while(++i){//开始玄学生成
//             x=f(x,c,p);//可能要用快速乘
//             z=z*abs(y-x)%p;//我们将每一次的（y-x）都累乘起来
//             cout<<"x:"<<x<<" y:"<<y<<endl;
//             if(x==y||!z)break;//如果跑完了环就再换一组试试（注意当z=0时，继续下去是没意义的）
//             if(!(i%127)||i==j){//我们不仅在等127次之后gcd我们还会倍增的来gcd
//                 g=gcd(z,p);
//                 if(g>1)return g;
//                 if(i==j)y=x,j<<=1;//维护倍增正确性，并判环（一箭双雕）
//             }
//         }
//     }
// }


int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    srand(time(NULL));
    cout<<rho(221)<<endl;
    cout<<endl;
    cout<<rho1(221)<<endl;
    return 0;
}