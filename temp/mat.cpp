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

#define M 2
struct Mat {
    int a[M][M];
    Mat() {
        Ms(a,0);
    }
    void eye() {
        Fo(i,0,M-1) a[i][i] = 1;
    }
    Mat operator * (Mat &b) {
        Mat res;
        Fo(i,0,M-1)
            Fo(j,0,M-1)
                Fo(k,0,M-1) {
                    res.a[i][j] += this->a[i][k]*b.a[k][j];
                }
        return res;
    }
    Mat operator + (Mat &b) {
        Mat res;
        Fo(i,0,M-1)
            Fo(j,0,M-1)
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
        Fo(i,0,M-1) {
            Fo(j,0,M-1) {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
};

// const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif

    return 0;
}