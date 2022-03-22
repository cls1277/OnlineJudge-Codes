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

#define MAXN 2505
struct Edge {
    LL next , to , len;
};
Edge e[6300*2];
LL head[MAXN] , tot , n , m , s , t , dis[MAXN] , vis[MAXN];

void add(LL x , LL y , LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

void spfa() {
    Ms(dis , 0x3f);
    Ms(vis , 0);
    queue<LL>q;
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()) {
        LL u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=head[u]; i; i=e[i].next) {
            LL v = e[i].to;
            if(dis[v]>dis[u]+e[i].len) {
                dis[v] = dis[u]+e[i].len;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    // freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>s>>t;
    Fo(i,1,m) {
        LL x , y, z;
        cin>>x>>y>>z;
        add(x , y , z);
        add(y , x , z);
    }
    spfa();
    cout<<dis[t];
    return 0;
}