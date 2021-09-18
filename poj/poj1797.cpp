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

#define MAXN 1005
struct Edge {
    LL next , to , len;
    Edge(){}
    Edge(LL nn , LL tt , LL ll) {
        next = nn , to = tt , len = ll;
    }
};
Edge e[1000005];
LL n , m , b , head[MAXN] , tot , dis[MAXN] , T , tt;

bool operator < (const Edge &a , const Edge &b) {
    return a.len<b.len;
}

void add(LL x , LL y , LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

void dij(LL s) {
    Ms(dis , 0);
    priority_queue<Edge>q;
    dis[s]=INF;
    q.push(Edge(s,0,dis[s]));
    while(!q.empty()) {
        Edge u = q.top();
        q.pop();
        if(dis[u.next]!=u.len) continue;
        for(int i=head[u.next]; i; i=e[i].next) {
            LL v = e[i].to;
            if(dis[v]<min(dis[u.next],e[i].len)) {
                dis[v] = min(dis[u.next],e[i].len);
                q.push(Edge(v,0,dis[v]));
            }
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    T=read();
	//cin>>T;
    while(T--) {
    	printf("Scenario #%d:\n",(++tt));
    	n=read(); m=read();
		//cout<<"Scenario #"<<(++tt)<<":"<<endl;
	    //cin>>n>>m;
	    tot=0; Ms(head,0);
	    Fo(i,1,m) {
	        LL x , y , z;
	        x=read(); y=read(); z=read();
			//cin>>x>>y>>z;
	        add(x , y , z);
	        add(y , x , z);
	    }
	    dij(1); 
		printf("%d\n\n",dis[n]);
		//cout<<dis[n]<<endl<<endl;  	
	}
    return 0;
}
