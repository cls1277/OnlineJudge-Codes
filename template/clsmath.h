//By cls1277
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
using std::cout;
using std::memset;
using std::abs;
using std::max;
using std::min;
using std::swap;
using std::vector;
using std::sqrt;
using std::rand;
using std::map;

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

#define M 2
struct Mat {
    int a[M][M];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    void eye() {
        for(int i=0; i<M; i++) a[i][i] = 1;
    }
    Mat operator * (Mat &b) {
        Mat res;
        for(int i=0; i<M; i++)
            for(int j=0; j<M; j++)
                for(int k=0; k<M; k++)
                    res.a[i][j] += this->a[i][k]*b.a[k][j];
        return res;
    }
    Mat operator + (Mat &b) {
        Mat res;
        for(int i=0; i<M; i++)
            for(int j=0; j<M; j++)
                res.a[i][j] = this->a[i][j]+b.a[i][j];
        return res;
    }
    Mat pow(int b) {
        Mat res , a=*this;
        res.eye();        
        while(b) {
            if(b&1)
                res = res*a;
            a = a*a;
            b>>=1;
        }
        return res;
    }
    void print() {
        for(int i=0; i<M; i++) {
            for(int j=0; j<M; j++)
                cout<<a[i][j]<<" ";
            cout<<'\n';
        }
    }
};

LL gcd(LL x, LL y) {
    return y?gcd(y, x%y):x;
}

const int maxn = 1e3+5;
void getprime(int maxx, int pri[]) {
    bool vis[maxn]; int cnt=0;
    memset(vis, 0, sizeof(vis));
    for(int i=2; i<=maxx; i++) {
        if(!vis[i]) pri[cnt++]=i;
        for(int j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) break;
        }
    }
}

void getphi(int maxx, int phi[]) {
    bool vis[maxn]; int cnt=0, pri[maxn];
    memset(vis, 0, sizeof(vis));
    for(int i=2; i<=maxx; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) {
                phi[i*pri[j]] = phi[i]*pri[j];
                break;
            } else {
                phi[i*pri[j]] = phi[i]*(pri[j]-1);
            }
        }
    }
}

void getmu(int maxx, int mu[]) {
    bool vis[maxn]; int cnt=0, pri[maxn];
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    for(int i=2; i<=maxx; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            pri[cnt++] = i;
        }
        for(int j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j])
                mu[i*pri[j]] = -mu[i];             
            else {
                mu[i*pri[j]] = 0;
                break;
            }
        }
    }
}

inline ULL qmul(ULL a, ULL b, const ULL mod){
    LL c=(LL)(a)*b-(LL)((ULL)((LD)(a)*b/mod)*mod);
    return c<0? c+mod:(c<mod? c:c-mod);
}

inline LL qpow(LL a, LL b, LL mod) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = qmul(res,a,mod);
        a = qmul(a,a,mod);
        b>>=1;
    }
    return res;
}

bool miller_rabin(LL x) {
    if(x==2) return true;
    if(x<2||x%2==0) return false;
    LL A[12]={2,3,5,7,11,13,17,19,23,29,31,37}, sz=11;
    //int范围内只需检查2,7,61
    //long long范围2,325,9375,28178,450775,9780504,1795265022
    //3E15内2,2570940,880937,610386380,4130785767
    //4E13内2,2570940,211991001,3749873356
    for(int i=0; i<=sz; i++)
        if(x==A[i])
            return true;
    LL m=x-1, k=0;
    while(m%2==0) {
        k++;
        m>>=1;
    }
    for(int i=0; i<=sz; i++) {
        LL y = qpow(A[i],m,x), z;
        z = y;
        for(int j=1; j<=k; j++) {
            y = qmul(y,y,x);
            if(y==1&&z!=1&&z!=x-1)
                return false;
            z = y;
        }
        if(y!=1) return false;
    }
    return true;
}

LL rho_function(LL x , LL c , LL mod) {
    return (qmul(x, x, mod)+c)%mod;
}

LL rho(LL n) {
    LL x, y, i, j, c, z;
    while(1) {
        i=0;j=1;z=1;
        x=y=rand()%n; c=rand()%n;
        while(++i) {
            x = rho_function(x, c, n);
            z = qmul(z, abs(y-x), n);
            if(!z || x==y) break;
            if(i==j || i%127==0) {
                LL g = gcd(z, n);
                if(g > 1) return g;
                if(i == j) {
                    j<<=1;
                    y=x;
                }
            }
        }
    }
}

LL max_prime_factor = 0;

void dfs(LL n) {
    if(n<max_prime_factor || n<2)
        return ;
    if(miller_rabin(n)) {
        max_prime_factor = max(max_prime_factor,n);
        return ;
    }
    LL p=n;
    p = rho(n);
    while(n%p == 0) n/=p;
    dfs(n); dfs(p);
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
        x=1; y=0;
        return a;
    }
    LL d=exgcd(b, a%b, x, y);
    LL k = x; x = y;
    y = k-a/b*y;
    return d;
}

//卡常gcd
inline int ctz(LL x) { return __builtin_ctzll(x); }
LL fast_gcd(LL a, LL b) {
    if(!a) return b; if(!b) return a;
    int t = ctz(a | b);
    a >>= ctz(a);
    do {
        b >>= ctz(b);
        if(a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << t;
}

LL inv[maxn];

LL inv1(LL x , LL y) {
    return qpow(x,y-2,y);
}

void inv2(LL n , LL mod) {
    inv[1] = 1;
    for(int i=2; i<=n; i++)
        inv[i] = (mod-mod/i)%mod*inv[mod%i]%mod;
}

//阶乘逆元
LL frac[maxn];
void inv3(LL n , LL mod) {
    frac[0] = 1;
    for(int i=1; i<=n; i++)
        frac[i] = frac[i-1]*i%mod;
    inv[n] = qpow(frac[n],mod-2,mod);
    for(int i=n-1; i>=0; i--)
        inv[i] = inv[i+1]*(i+1)%mod;
}

LL inv4(LL n, LL mod) {
    LL x, y;
    exgcd(n, mod, x, y);
    return (x+mod)%mod;
}

LL C(LL n, LL m, LL mod) {
    LL res=1;
    for(int i=1; i<=m; i++)
        res=res*(n-m+i)%mod*qpow(i,mod-2,mod)%mod;
    return res;
}

//求C_{n+m}^n mod p的值
LL lucas(LL n , LL m , LL mod) {
    if(!m) return 1;
    return C(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
}

const double eps = 1e-10;
LL mat[maxn][maxn];
//第n+1列是y值，第i个变量的值为mat[i][n+1]/mat[i][i]
bool gauss(int n) {
    for(int i=1; i<=n; i++) {
        LL maxrow=i;
        for(int j=i+1; j<=n; j++)
            if(mat[j][i]>mat[maxrow][i])
                maxrow = j;
        if(fabs(mat[maxrow][i])<=eps) return false;
        for(int j=1; j<=n+1; j++)
            swap(mat[maxrow][j],mat[i][j]);
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            double p=mat[j][i]/mat[i][i];
            for(int k=i+1; k<=n+1; k++)
                mat[j][k]-=mat[i][k]*p;
        }
    }
    return true;
}

void init(LL n, int phi[], bool exi[], bool vis[]) {
    //预处理exi和vis为0
    for(int i=1; i<=n; i++) exi[i]=vis[i]=0;
    int pri[maxn]; LL cnt = 0;
    phi[1]=1;
    for(int i=2; i<=n; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j=0; j<cnt; j++) {
            if(i*pri[j]>n) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            } else {
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
            }
        }
    }
    exi[2]=exi[4]=1;
    for(int i=1; i<cnt; i++) {
        LL p=pri[i];
        for(LL q=p; q<=n; q*=p) {
            exi[q] = 1;
            if(2*q<=n) exi[2*q]=1;
        }
    }
}

//之前应手动运行init(max_n);
//答案存在root中
void primitive_root(LL n, LL phi[], bool exi[], vector<LL>root) {
    if(!exi[n]) return ;
    LL tempn=n; n=phi[n];
    vector<LL>facts;
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            facts.push_back(i);
            if(i!=n/i)
                facts.push_back(n/i);
        }
    }
    LL i=0;
    while(1) {
        i++;
        if(gcd(i,tempn)!=1) continue;
        bool is=true;
        for(auto fact:facts) {
            LL t=qpow(i,fact,tempn);//tempn!!!
            if(fact!=n&&t==1) {
                is = false;
                break;
            }
        }
        if(is) break;
    }
    LL tempi=i, p=i;
    for(int i=1; i<=n; i++) {
        if(gcd(i,n)==1)
            root.push_back(p);
        p=p*tempi%tempn;
    }
}

//给定N,p 求解x^2同余N(mod p)
//此处的mod与下面的p都是模数
//quad_n = n ，quad_a是找到的满足a^2-n是二次非剩余的a，quad_a = a
LL quad_a, quad_n, mod;

LL lrand(LL x, LL p) {
    return qpow(x%p, (p-1)/2, p);
}

struct Zi {
    LL x, y;
    Zi operator * (Zi m) {
        return {(x*m.x%mod+y*m.y%mod*(quad_a*quad_a%mod-quad_n)%mod)%mod,(x*m.y%mod+y*m.x%mod)%mod};
    }
    Zi qpow(LL b) {
        Zi res={1,0},x=(*this);
        while(b) {
            if(b&1)
                res=res*x;
            x=x*x;
            b>>=1;
        }
        return res;
    }
};

LL quad_residue(LL n, LL p) {
    if(n%p==0) return 0;
    if(lrand(n, p)!=1) return -1;//无解
    LL i=rand()%p;
    quad_n = n;
    while(1) {
        if(lrand(i*i-n, p)==p-1) {
            quad_a = i;
            break;
        } else i=rand()%p;
    } 
    Zi ans={quad_a,1};
    return ans.qpow((p+1)/2).x%p;
    /*
    //调整ans；求另一个答案
        if(ans<0) ans=(p+ans)%p;
        ans2=(p-ans)%p;
    */
}

//_M = m[i]的累乘
//f[]:余数，m[]:模数
//以下代码用qmul卡常
LL CRT(LL f[], LL m[], LL n, LL _M) {
    LL ans = 0;
    for(int i=1; i<=n; i++) {
        LL Mi=_M/m[i], inv, z;
        exgcd(Mi, m[i], inv, z);
        ans = (ans+qmul(qmul(Mi, inv, _M), f[i], _M))%_M;
    }
    return (ans+_M)%_M;
}

//a^x=b mod p，给定a,b,p 求最小非负x
LL bsgs(LL a, LL b, LL p) {
    LL t=sqrt(p)+1;
    map<LL,LL>mp;
    LL m=b%p;
    for(int i=0; i<t; i++) {
        mp[m]=i+1;
        m=m*a%p;
    }
    LL temp=qpow(a,t,p);
    m=temp;
    for(int i=1; i<=t; i++) {
        if(mp[m])
            return i*t-mp[m]+1;
        m=m*temp%p;
    }
    return -1;//无解
}

//f(i)=floor(n/i)=t的取值范围是[l,r]
void divide_block(LL n) {
    for(LL l=1,r; l<=n; l=r+1) {
        LL t=n/l;
        if(t) r=min(n,n/t);
        else r=n;
        //根据题目要求在[l,r]内进行对应操作
    }
}