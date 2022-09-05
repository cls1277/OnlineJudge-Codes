//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//复数库 可能会慢
#include<complex>

using namespace std;

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

#define PI acos(-1)

#define M 2
struct Mat {
    LL a[M][M];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    void eye() {
        for(LL i=0; i<M; i++) a[i][i] = 1;
    }
    Mat operator * (Mat &b) {
        Mat res;
        for(LL i=0; i<M; i++)
            for(LL j=0; j<M; j++)
                for(LL k=0; k<M; k++)
                    res.a[i][j] += this->a[i][k]*b.a[k][j];
        return res;
    }
    Mat operator + (Mat &b) {
        Mat res;
        for(LL i=0; i<M; i++)
            for(LL j=0; j<M; j++)
                res.a[i][j] = this->a[i][j]+b.a[i][j];
        return res;
    }
    Mat pow(LL b) {
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
    void prLL() {
        for(LL i=0; i<M; i++) {
            for(LL j=0; j<M; j++)
                cout<<a[i][j]<<" ";
            cout<<'\n';
        }
    }
};

LL gcd(LL x, LL y) {
    return y?gcd(y, x%y):x;
}

const LL maxn = 1e3+5;
void getprime(LL maxx, LL pri[]) {
    bool vis[maxn]; LL cnt=0;
    memset(vis, 0, sizeof(vis));
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) pri[cnt++]=i;
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) break;
        }
    }
}

void getphi(LL maxx, LL phi[]) {
    bool vis[maxn]; LL cnt=0, pri[maxn];
    memset(vis, 0, sizeof(vis));
    phi[1] = 1;
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(LL j=0; j<cnt; j++) {
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

LL getonephi(LL x, LL mod) {
    LL temp = x;
    for(LL i=2; i<=sqrt(x); i++) {
        if(x%i) continue;
        temp = temp-temp/i;
        while(x%i==0) x/=i;
    }
    if(x!=1) temp=temp-temp/x;
    return temp%mod;
}

void getmu(LL maxx, LL mu[]) {
    bool vis[maxn]; LL cnt=0, pri[maxn];
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            pri[cnt++] = i;
        }
        for(LL j=0; j<cnt; j++) {
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

// qmul的另一种写法
inline LL qmul2(LL a, LL b, LL p) {
    LL ans = 0;
    while(b) {
        if(b&1) ans = (ans+a)%p;
        a = a*2%p;
        b>>=1;
    }
    return ans;
}

inline LL qpow(LL a, LL b, LL mod = 19260817) {
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
    //LL范围内只需检查2,7,61
    //long long范围2,325,9375,28178,450775,9780504,1795265022
    //3E15内2,2570940,880937,610386380,4130785767
    //4E13内2,2570940,211991001,3749873356
    for(LL i=0; i<=sz; i++)
        if(x==A[i])
            return true;
    LL m=x-1, k=0;
    while(m%2==0) {
        k++;
        m>>=1;
    }
    for(LL i=0; i<=sz; i++) {
        LL y = qpow(A[i],m,x), z;
        z = y;
        for(LL j=1; j<=k; j++) {
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

//卡常gcd stein算法 去掉了取模 加快了速度
inline LL ctz(LL x) { return __builtin_ctzll(x); }
LL fast_gcd(LL a, LL b) {
    if(!a) return b; if(!b) return a;
    LL t = ctz(a | b);
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
    for(LL i=2; i<=n; i++)
        inv[i] = (mod-mod/i)%mod*inv[mod%i]%mod;
}

//阶乘逆元
LL frac[maxn];
void inv3(LL n , LL mod) {
    frac[0] = 1;
    for(LL i=1; i<=n; i++)
        frac[i] = frac[i-1]*i%mod;
    inv[n] = qpow(frac[n],mod-2,mod);
    for(LL i=n-1; i>=0; i--)
        inv[i] = inv[i+1]*(i+1)%mod;
}

LL inv4(LL n, LL mod) {
    LL x, y;
    exgcd(n, mod, x, y);
    return (x+mod)%mod;
}

LL C(LL n, LL m, LL mod) {
    LL res=1;
    for(LL i=1; i<=m; i++)
        res=res*(n-m+i)%mod*qpow(i,mod-2,mod)%mod;
    return res;
}

//求C_{n+m}^n mod p的值
LL lucas(LL n , LL m , LL mod) {
    if(!m) return 1;
    return C(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
}

const LD eps = 1e-10;
LL mat[maxn][maxn];
//第n+1列是y值，第i个变量的值为mat[i][n+1]/mat[i][i]
bool gauss(LL n) {
    for(LL i=1; i<=n; i++) {
        LL maxrow=i;
        for(LL j=i+1; j<=n; j++)
            if(mat[j][i]>mat[maxrow][i])
                maxrow = j;
        if(fabs(mat[maxrow][i])<=eps) return false;
        for(LL j=1; j<=n+1; j++)
            swap(mat[maxrow][j],mat[i][j]);
        for(LL j=1; j<=n; j++) {
            if(i==j) continue;
            LD p=mat[j][i]/mat[i][i];
            for(LL k=i+1; k<=n+1; k++)
                mat[j][k]-=mat[i][k]*p;
        }
    }
    return true;
}

//原根

void init(LL n, LL phi[], bool exi[], bool vis[]) {
    //预处理exi和vis为0
    for(LL i=1; i<=n; i++) exi[i]=vis[i]=0;
    LL pri[maxn]; LL cnt = 0;
    phi[1]=1;
    for(LL i=2; i<=n; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(LL j=0; j<cnt; j++) {
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
    for(LL i=1; i<cnt; i++) {
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
    for(LL i=1; i<=sqrt(n); i++) {
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
    for(LL i=1; i<=n; i++) {
        if(gcd(i,n)==1)
            root.push_back(p);
        p=p*tempi%tempn;
    }
}

//二次剩余：
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
    for(LL i=1; i<=n; i++) {
        LL Mi=_M/m[i], inv, z;
        exgcd(Mi, m[i], inv, z);
        ans = (ans+qmul(qmul(Mi, inv, _M), f[i], _M))%_M;
    }
    return (ans+_M)%_M;
}

//a^x=b mod p，给定a,b,p 求最小非负x
//a p互质
LL bsgs(LL a, LL b, LL p) {
    LL t=sqrt(p)+1;
    map<LL,LL>mp;
    LL m=b%p;
    for(LL i=0; i<t; i++) {
        mp[m]=i+1;
        m=m*a%p;
    }
    LL temp=qpow(a,t,p);
    m=temp;
    for(LL i=1; i<=t; i++) {
        if(mp[m])
            return i*t-mp[m]+1;
        m=m*temp%p;
    }
    return -1;//无解
}

//a^x=b mod p，给定a,b,p 求最小非负x
//a p不互质
LL exbsgs(LL a, LL b, LL p) {
    if(b==1||p==1) return 0;
    LL d,cnt=0,ai=1;
    while((d=gcd(a,p))>1) {
        if(b%d) return -1;
        b/=d; p/=d; ai=(ai*a/d)%p; cnt++;
        if(b==ai) return cnt;
    }
    LL x,y;
    exgcd(ai,p,x,y);
    LL inv=(x+p)%p;
    LL res=bsgs(a,b*inv%p,p);
    if(res==-1) return -1;
    return res+cnt;
}

//数论分块：f(i)=floor(n/i)=t的取值范围是[l,r]
void divide_block(LL n) {
    for(LL l=1,r; l<=n; l=r+1) {
        LL t=n/l;
        if(t) r=min(n,n/t);
        else r=n;
        //根据题目要求在[l,r]内进行对应操作
    }
}

//旋转染色polya n个点n种颜色，莫比乌斯反演后
LL polya_rotate(LL n, LL mod) {
    LL res = 0;
    for(LL i=1; i<=sqrt(n); i++) {
        if(n%i) continue;
        res = (res+qpow(n, i, mod)*getonephi(n/i, mod)%mod)%mod;
        if(i*i!=n) res=(res+qpow(n, n/i, mod)*getonephi(i, mod)%mod)%mod;
    }
    return res*qpow(n, mod-2, mod)%mod;
}

//翻转染色polya n个结点，m种颜色
LL polya_roll(LL n, LL m) {
    LL ans = 0;
    if(n&1) ans = n*qpow(m, (n+1)/2);
    else {
        ans = n/2*qpow(m, n/2);
        ans = n/2*qpow(m, n/2+1);
    }
    ans/=n;
    return ans;
}

//旋转+翻转染色 polya n个结点 m种颜色
LL polya_roll_rotate(LL n, LL m) {
    LL ans = 0;
    for(LL i=1; i<=n; i++) ans+=qpow(m, gcd(i, n));
    if(n&1) ans = n*qpow(m, (n+1)/2);
    else {
        ans = n/2*qpow(m, n/2);
        ans = n/2*qpow(m, n/2+1);
    }
    ans/=2*n;
    return ans;
}

//杜教筛sum
//大概预处理到n^(2/3)

LL maxx = INT_MAX;//输入的最大数
#define N pow(maxx, (2/3))
unordered_map<LL,LL>hashmu;
unordered_map<LL,LL>hashphi;

LL summu(LL n) {
    // if(n<=N) return mu[n]; //预处理莫比乌斯函数的前N项和，直接输出
    if(hashmu[n]) return hashmu[n];
    LL res = 1;
    for(LL i=2,j; i<=n; i=j+1) {
        j=n/(n/i);
        res -= summu(n/i)*(j-i+1);
    }
    return hashmu[n]=res;
}

LL sumphi(LL n) {
    // if(n<=N) return phi[n]; //预处理欧拉函数的前N项和，直接输出
    if(hashphi[n]) return hashphi[n];
    LL res = n*(n+1)/2;
    for(LL i=2,j; i<=n; i=j+1) {
        j = n/(n/i);
        res -= 1LL*sumphi(n/i)*(j-i+1);
    }
    return hashphi[n] = res;
}

//下面的代码是调用complex库的FFT写法
//注释掉的是自己写的复数结构体的FFT写法
/*
struct Complex {
	LD x , y;
	Complex(LD xx=0 , LD yy=0) {
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
#define cp Complex
*/

#define cp complex<LD>

//高精度乘法时一定要逆序存储

void fft(cp a[], LL n, LL inv) {
    LL r[maxn];//记得放到外面
    LL bit=1; while((1<<bit)<n) bit++;
    for(LL i=0; i<n; i++) {
        r[i] = (r[i>>1]>>1) | ((i&1)<<(bit-1));
        if(i<r[i]) swap(a[i], a[r[i]]);
    }
    for(LL mid=1; mid<n; mid<<=1) {
        cp wi(cos(PI/mid), inv*sin(PI/mid));
        for(LL i=0; i<n; i+=mid<<1) {
            cp wn(1,0);
            for(LL j=0; j<mid; j++,wn=wn*wi) {
                cp x=a[i+j], y=wn*a[i+j+mid];
                a[i+j]=x+y, a[i+j+mid]=x-y;
            }
        }
    }
}

//g是模数的原根
//通常意义下，模数是998244353
#define g 3

void ntt(LL a[], LL n, LL inv) {
    LL r[maxn];//记得放到外面
    LL bit=1; while((1<<bit)<n) bit++;
    for(LL i=0; i<n; i++) {
        r[i] = (r[i>>1]>>1) | ((i&1)<<(bit-1));
        if(i<r[i]) swap(a[i], a[r[i]]);
    }
    for(LL mid=1; mid<n; mid<<=1) {
        LL gi=qpow(g, (mod-1)/(mid<<1), mod);
        if(inv==-1) gi=qpow(gi, mod-2, mod);
        for(LL i=0; i<n; i+=mid<<1) {
            LL gn = 1;
            for(LL j=0; j<mid; j++,gn=gn*gi) {
                LL x=a[i+j], y=gn*a[i+j+mid]%mod;
                a[i+j]=(x+y)%mod; a[i+j+mid]=(x-y+mod)%mod;
            }
        }
    }    
}

LL invert(LL x) {
    LL bit = 1;
    while((1<<bit)<x) bit++;
    return (1<<bit);
}

void fft_init() {
    LL n, m, t; cp a[maxn], b[maxn];//记得放到外面
    cin>>n>>m; t=invert(n+m);
    // for(int i=0; i<=n; i++) cin>>a[i].x;
    // for(int i=0; i<=m; i++) cin>>b[i].x;
    for(int i=0; i<=n; i++) {
        double x; cin>>x;
        a[i].real(x);
    }
    for(int i=0; i<=m; i++) {
        double x; cin>>x;
        b[i].real(x);
    }
    fft(a, t, 1);
    fft(b, t, 1);
    for(int i=0; i<=t; i++) a[i]=a[i]*b[i];
    fft(a, t, -1);
    for(int i=0; i<=n+m; i++) cout<<(int)(a[i].real()/t+0.5)<<" ";
    // for(int i=0; i<=n+m; i++) cout<<(int)(a[i].x/t+0.5)<<" ";
}

void ntt_init() {
    LL n, m, t; LL a[maxn], b[maxn];
    cin>>n>>m; t=invert(n+m);
    for(int i=0; i<=n; i++) cin>>a[i];
    for(int i=0; i<=m; i++) cin>>b[i];
    ntt(a, t, 1);
    ntt(b, t, 1);
    for(int i=0; i<=t; i++) a[i]=a[i]*b[i]%mod;
    ntt(a, t, -1);
    for(int i=0; i<=n+m; i++) cout<<a[i]*qpow(t, mod-2, mod)%mod<<" ";
}

// 高精度模板（我的，有点慢）
// 加减乘除模

int stringmax(string num1, string num2) {
    LL len1=num1.length(), len2=num2.length();
    bool flag = 0, flag2 = 0;
    if(len2>len1) flag = 1;
    if(len1==len2) {
        Fo(i,0,len1-1) {
            if(num2[i]>num1[i]) {
                flag = 1;
                break;
            } else if(num1[i]>num2[i]) {
                flag2 = 1;
                break;
            }
        }
        if(flag) {
        	return 1;
		}
        if(!flag2) {
            return 0; //num1 == num2
    	} else {
    		return 2;
		}
    }
    if(flag) return 1; // num1 < num2
    return 2; // num1 > num2;
} 

string stringadd(string num1, string num2) {
    string num3 = "";
    LL len1 = num1.length(), len2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    LL len3 = min(len1, len2);
    LL pre = 0;
    Fo(i,0,len3-1) {
        LL a = num1[i]-'0', b = num2[i]-'0';
        LL c = (a+b+pre);
        if(c>=10) {
        	pre = c/10;
        	c %= 10;
		} else {
			pre = 0;
		}
        num3 += c+'0';
    }
    if(len3==len1) {
        Fo(i,len3,len2-1) {
            LL a = num2[i]-'0';
            LL c = (a+pre);
	        if(c>=10) {
	        	pre = c/10;
	        	c %= 10;
			} else {
				pre = 0;
			}
            num3 += c+'0';
        }
    } else {
        Fo(i,len3,len1-1) {
            LL a = num1[i]-'0';
            LL c = (a+pre);
	        if(c>=10) {
	        	pre = c/10;
	        	c %= 10;
			} else {
				pre = 0;
			}
            num3 += c+'0';
        }
    }
    if(pre) num3 += pre+'0';
    reverse(num3.begin(), num3.end());
    return num3;
}

string stringdel(string num1, string num2) {
	int op = stringmax(num1, num2);
	if(!op) return "0";
	else if(op==1) swap(num1, num2); 
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    LL len1=num1.length(), len2=num2.length();
    bool pre = 0;
    string num3 = "";
    Fo(i,0,len2-1) {
        LL a = num1[i]-'0', b = num2[i]-'0';
        if(pre) {
            if(!a) {
                pre = 1;
                a = 9;
            } else {
                a--;
                pre = 0;
            }
        }
        if(a>=b) {
            num3 += (a-b)+'0';
        } else {
            pre = 1;
            a += 10;
            num3 += (a-b)+'0';
        }
    }
    if(len1>len2) {
        Fo(i,len2,len1-1) {
            LL a = num1[i]-'0';
            if(pre) {
                if(!a) {
                    pre = 1;
                    a = 9;
                } else {
                    a--;
                    pre = 0;
                }                
            }
            num3 += a+'0';
        }
    }
    reverse(num3.begin(), num3.end());
    LL l = num3.length(), top = 0;
    string num4 = "";
    if(op==1) num4 += '-';
    Fo(i,0,l-1) {
        if(num3[i]!='0') {
            top = i;
            break;
        }
    }
    Fo(i,top,l-1) num4 += num3[i];
    return num4;
}

string stringmul(string num1, char num2) {
    string num3 = "";
    LL b = num2-'0';
    LL len = num1.length();
    LL pre = 0;
    reverse(num1.begin(), num1.end());
    Fo(i,0,len-1) {
        LL a = num1[i]-'0';
        LL c = a*b+pre;
        if(c>=10) {
            pre = c/10;
            c %= 10;
        } else {
            pre = 0;
        }
        num3 += c+'0';
    }
    if(pre) num3 += pre+'0';
    reverse(num3.begin(), num3.end());
    return num3;
}

string stringmul2(string num1, string num2) {
    LL len = num2.length();
    string num3 = "0";
    string num4 = "";
    Ro(i,len-1,0) {
        string temp = stringmul(num1, num2[i]);
        temp += num4;
        num4 += '0';
        num3 = stringadd(num3, temp);
    }
    if(!atoi(num3.c_str())) return "0";
    else {
        LL l = num3.length();
        LL top = 0;
        Fo(i,0,l-1) {
            if(num3[i]!='0') {
                top = i;
                break;
            }
        }
        string ans = "";
        Fo(i,top,l-1) ans += num3[i]; 
        return ans;
    }
}

string stringdiv1(string num1, LL num2) {
    string num3 = "";
    LL len = num1.length();
    LL pre = 0;
    Fo(i,0,len-1) {
        pre = pre*10+(num1[i]-'0');
        if(pre<num2) continue;
        Ro(j,9,1) {
            if(num2*j<=pre) {
                num3 += j+'0';
                pre -= num2*j;
                break;
            }
        }
    }
    return num3;
}

string stringdiv2(string num1, string num2) {
    int op = stringmax(num1, num2);
    if(!op) return "1";
    else if(op==1) return "0";
    else {
        string num3="", num4="";
        LL len1=num1.length(), len2=num2.length();
        Fo(i,0,len1-1) {
            num3 += num1[i];
            int op1 = stringmax(num3, num2);
            if(op1==1) continue;
            Ro(j,9,1) {
                string temp = stringmul(num2, j+'0');
                int op2 = stringmax(temp, num3);
                if(op2<2) {
                    num4 += j+'0';
                    num3 = stringdel(num3, temp);
                    break;
                }
            }
        }
        LL l = num4.length(), top = 0;
        string num5 = "";
        Fo(i,0,l-1) {
            if(num4[i]!='0') {
                top = i;
                break;
            }
        }
        Fo(i,top,l-1) num5 += num4[i];
        return num5;
    }
}

string stringmod(string num1, string num2) {
    string divv = stringdiv2(num1, num2);
    return stringdel(num1, stringmul2(num2, divv));    
}