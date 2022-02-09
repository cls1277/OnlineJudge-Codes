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

const LL maxn = 1e6+5;

LL pri[maxn],phi[maxn],cnt;

LL qpow(LL a, LL b, LL mod) {
    LL res=1;
    while(b) {
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

bool vis[maxn], exi[maxn];

void init(LL n) {
    Ms(vis,0); Ms(exi,0);
    phi[1]=1;
    Fo(i,2,n) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        Fo(j,0,cnt-1) {
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
    // Fo(i,0,cnt-1)
    //     cout<<pri[i]<<" ";
    exi[2]=exi[4]=1;
    Fo(i,1,cnt-1) {
        LL p=pri[i];
        for(LL q=p; q<=n; q*=p) {
            exi[q] = 1;
            if(2*q<=n) exi[2*q]=1;
        }
    }
}

LL gcd(LL a, LL b) {
    return b?gcd(b,a%b):a;
}

vector<LL>root;

void getroot(LL n) {
    root.clear();
    if(!exi[n]) return ;
    LL tempn=n; n=phi[n];
    // cout<<n<<endl;
    vector<LL>facts;
    Fo(i,1,sqrt(n)) {
        if(n%i==0) {
            facts.push_back(i);
            if(i!=n/i)
                facts.push_back(n/i);
        }
    }
    // cout<<"#";
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
    // cout<<"*";
    LL tempi=i, p=i;
    Fo(i,1,n) {
        if(gcd(i,n)==1)
            root.push_back(p);
        p=p*tempi%tempn;
    }
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    init(1000000);
    LL T; T=read();//cin>>T;
    while(T--) {
        LL n,d,c; n=read(); d=read();//cin>>n>>d;
        getroot(n);
        // cout<<root.size()<<endl;
        c=root.size();
        printf("%lld\n",c);
        // cout<<c<<endl;
        sort(root.begin(),root.end());
        for(LL i=d; i<=c; i+=d)
            printf("%lld ",root[i-1]);
            // cout<<root[i-1]<<" ";
        // cout<<endl;
        printf("\n");
    }
    return 0;
}