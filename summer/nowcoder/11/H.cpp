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

vector<int>fa;
int sz[maxn],dp2[maxn],dp5[maxn],ans[maxn];

void dfs1(int u,int fa){
    sz[u]=1;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}

void dfs(int u,int fa){
    int temp=u;
    int temp2=0,temp5=0;
    while(temp){
        if(temp%2==0){
            temp/=2;
            temp2++;
        }
        else break;
    }
    temp=u;
    while(temp){
        if(temp%5==0){
            temp/=5;
            temp5++;
        }
        else break;
    }
    dp2[u] = dp2[fa]+temp2;
    dp5[u] = dp5[fa]+temp5;
    ans[u] = ans[fa](sz[fa]-sz[u]-1)*(dp2[u]+dp5[u]);
    // ans[u]=min(dp2[fa]+temp2*sz[u],dp5[fa]+temp5*sz[u]);
    //cout<<u<<' '<<temp2<<' '<<temp5<<endl;
    // dp2[u]+=sz[u]*temp2;
    // dp5[u]+=sz[u]*temp5;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)continue;
        dfs(v,u);
    }
}

int main(){
    // IO;
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    CLOSE;
    int n,q;cin>>n>>q;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(1,0);
    for(int i=1; i<=n; i++) sz[i]--;
    dfs(1,0);
    for(int i=1;i<=q;i++){
        int x;cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}
