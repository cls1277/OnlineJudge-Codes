 #include<bits/stdc++.h>
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<time.h>
#include <cstdio>
#include <iostream>
#include <vector>
#define ll long long

#define inf 0x3f3f3f3f
#define mods 1000000007
#define modd 998244353
#define PI acos(-1)
#define fi first
#define se second
#define lowbit(x) (x&(-x))
#define mp make_pair
#define pb push_back
#define si size()
#define E exp(1.0)
#define fixed cout.setf(ios::fixed)
#define fixeds(x) setprecision(x)
#define IOS ios::sync_with_stdio(false);cin.tie(0)
 using namespace std;
 ll gcd(ll a,ll b){if(a<0)a=-a;if(b<0)b=-b;return b==0?a:gcd(b,a%b);}
template<typename T>void read(T &res){bool flag=false;char ch;while(!isdigit(ch=getchar()))(ch=='-')&&(flag=true);
for(res=ch-48;isdigit(ch=getchar());res=(res<<1)+(res<<3)+ch - 48);flag&&(res=-res);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll qp(ll a,ll b,ll mod){ll ans=1;if(b==0){return ans%mod;}while(b){if(b%2==1){b--;ans=ans*a%mod;}a=a*a%mod;b=b/2;}return ans%mod;}//������%
ll qpn(ll a,ll b, ll p){ll ans = 1;a%=p;while(b){if(b&1){ans = (ans*a)%p;--b;}a =(a*a)%p;b >>= 1;}return ans%p;}//��Ԫ   (����*qp(��ĸ,mod-2,mod))%mod;

ll fact_pow(ll n,ll p){ll res=0;while(n){n/=p;res+=n;}return res;}
ll mult(ll a,ll b,ll p)
{
    a%=p;
    b%=p;
    ll r=0,v=a;
    while(b)
    {
        if(b&1)
        {
            r=(r+v)%p;

               r=(r+p)%p;
        }
        v<<=1;
        v=(v+p)%p;
        b>>=1;
    }
    return r%p;
}
ll pow_mod(ll x,ll n,ll mod)
{
    ll res=1;
    while(n)
    {
        if(n&1)
        res=mult(res,x,mod);
        x=mult(x,x,mod);
        n>>=1;
    }
    return res;
}
ll quick_pow(ll a,ll b,ll p){ll r=1,v=a%p;while(b){if(b&1)r=mult(r,v,p);v=mult(v,v,p);b>>=1;}return r;}
bool CH(ll a,ll n,ll x,ll t)
{ll r=quick_pow(a,x,n);ll z=r;for(ll i=1;i<=t;i++){r=mult(r,r,n);if(r==1&&z!=1&&z!=n-1)return true;z=r;}return r!=1;}
bool Miller_Rabin(ll n)
{if(n<2)return false;if(n==2)return true;if(!(n&1))return false;ll x=n-1,t=0;while(!(x&1)){x>>=1;t++;}
srand(time(NULL));ll o=8;for(ll i=0;i<o;i++){ll a=rand()%(n-1)+1;if(CH(a,n,x,t))return false;}return true;}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if (!b){
        x=1,y=0;
        return a;
    }
    ll ans=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ans;
}
ll INV(ll a,ll b){ll x,y;return exgcd(a,b,x,y),(x%b+b)%b;}
ll crt(ll x,ll p,ll mod){return INV(p/mod,mod)*(p/mod)*x;}
ll FAC(ll x,ll a,ll b)
{if(!x)return 1;ll ans=1;for(ll i=1;i<=b;i++)if(i%a)ans*=i,ans%=b;
ans=pow_mod(ans,x/b,b);for(ll i=1;i<=x%b;i++)if(i%a)ans*=i,ans%=b;return ans*FAC(x/a,a,b)%b;}
ll C(ll n,ll m,ll a,ll b)
{ll N=FAC(n,a,b),M=FAC(m,a,b),Z=FAC(n-m,a,b),sum=0,i;for(i=n;i;i=i/a)sum+=i/a;
for(i=m;i;i=i/a)sum-=i/a;for(i=n-m;i;i=i/a)sum-=i/a;return N*pow_mod(a,sum,b)%b*INV(M,b)%b*INV(Z,b)%b;}
ll exlucas(ll n,ll m,ll p)
{ll t=p,ans=0,i;for(i=2;i*i<=p;i++){ll k=1;while(t%i==0){k*=i,t/=i;}
ans+=crt(C(n,m,i,k),p,k),ans%=p;}if(t>1)ans+=crt(C(n,m,t,t),p,t),ans%=p;return ans % p;}
ll H(ll x,ll p)  //����
{
       ll ans=0;
    if(x==0)return 1;
    x=x%(2*p);
    if(x==0)x=2*p;
    for(int i=2;i<=x;++i)
    ans=(ans*i+(i%2==0?1:-1))%p;
    return (ans+p)%p;
}

struct ORZ{

int head[2],d[3],hurt[3];
bool vis[2];
int n,m,k=0,s,e,kk,ans;
struct node{
    int v,next,w;
}a[3];
void add(ll u,ll v,ll w)
{
    a[++k].next=head[u];
    a[k].w=w;
    a[k].v=v;
    head[u]=k;
}
void dij()
{
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0;
    priority_queue<pair<ll,ll> >q;
    q.push(mp(0,s));
    while(q.size()){
        ll u=q.top().se;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=a[i].next){
            ll v=a[i].v,w=a[i].w;
           if(d[v]>d[u]+w){
            d[v]=d[u]+w;

            q.push(mp(-d[v],v));
            }

        }
    }
}

};

const int INF=0x3f3f3f3f;
const int N=33000;

int L, l, maxl, minl, ans, pcnt, w, t;
struct node{ int x, y, l; }p[N];
bool Can( int i, int j ) {
    if( t*t==w && t<=l && p[i].l+p[j].l+t==L )
        if( p[i].x*p[j].y-p[i].y*p[j].x ) return 1;
    return 0;
}

int Dis( node a, node b ) {
    w=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(w);
}

void cle() {
    ans=INF; l=L>>1;
    for( int i=1; i<=L; i++ )
        for( int j=0; i*i+j*j<=l*l; j++ ) {
            t=sqrt( i*i+j*j );
            if( t*t==i*i+j*j ) {
                p[++pcnt].l=t;
                p[pcnt].x=i; p[pcnt].y=j;
            }
        }
}
int nani=0;
void wtf(){
if(nani!=0)nani++;

}
signed main() {
    scanf( "%d", &L );
    if( L&1 || L<4 ){ printf( "-1" ); return 0; }
    cle();wtf();wtf();wtf();wtf();wtf();wtf();
    for( int i=1; i<=pcnt; i++ )
        for( int j=i+1; j<=pcnt && p[i].l+p[j].l < L; j++ ) {
            t=Dis( p[i], p[j] );
            if( Can( i, j ) ) {wtf();wtf();wtf();wtf();wtf();
                maxl=max( t, max( p[i].l, p[j].l ) );
                minl=min( t, min( p[i].l, p[j].l ) );wtf();wtf();
                ans=min( ans, maxl-minl );wtf();wtf();wtf();wtf();
            }
        }
    if( ans>=INF ) {wtf();wtf();wtf();wtf();
        if( L%4 ) ans=1;
        else ans=0;
    }wtf();wtf();wtf();
    printf("%d\n",ans);
    return 0;
}
