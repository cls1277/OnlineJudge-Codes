#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int inf1=2147483647;
const ll INF=1e18;
#define IO freopen("in.in","r",stdin),freopen("out.out","w",stdout)
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int mod=998244353;
const int maxn=1e5+5;
struct edge{
    int v,next;
}e[maxn*2];
int tot=0,head[maxn];
void addedge(int u,int v){
    e[++tot].v=v;
    e[tot].next=head[u];
    head[u]=tot;
}

int sz[maxn];
void dfs(int u,int fa){
    sz[u]=1;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}

int res=0;
void dfs1(int u,int fa){
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)continue;
        if(sz[v]%2==0)res++;
        dfs1(v,u);
    }
}

int main(){
    IO;
    CLOSE;
    int T;cin>>T;
    while(T--){
        res=0;
        memset(head,0,sizeof(head));
        tot=0;
        int n;cin>>n;
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1,0);
        dfs1(1,0);
        cout<<(ll(pow(2,res)-1+mod)%mod)<<endl;
    }
    return 0;
}