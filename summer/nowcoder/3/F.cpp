#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+5;
struct edge{
    int nxt,mark;
}pre[200010];
int n,m,idx,cnt,tot,q;
int head[100010],DFN[100010],LOW[100010];
bool cut[100010];
void add (int x,int y){
    pre[++cnt].nxt=y;
    pre[cnt].mark=head[x];
    head[x]=cnt;
}
void tarjan (int u,int fa){
    DFN[u]=LOW[u]=++idx;
    int child=0;
    for (int i=head[u];i!=0;i=pre[i].mark){
        int nx=pre[i].nxt;
        if (!DFN[nx]){
            tarjan (nx,fa);
            LOW[u]=min (LOW[u],LOW[nx]);
            if (LOW[nx]>=DFN[u]&&u!=fa)
                cut[u]=1;
            if(u==fa)
                child++;
        }
        LOW[u]=min (LOW[u],DFN[nx]);
    }
    if (child>=2&&u==fa)
        cut[u]=1;
}
int degree[maxn];
unordered_map<ll,ll>mm;
int main(){
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    memset (DFN,0,sizeof (DFN));
    memset (head,0,sizeof (head));
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int a,b;
        scanf ("%d%d",&a,&b);
        ll temp=a*1000000+b;
        ll temp1=b*1000000+a;
        if((!mm[temp])||(!mm[temp1]))mm[temp]++,mm[temp1]++;
        else continue;
        add (a,b);
        add (b,a);
        degree[a]++,degree[b]++;
    }
    scanf ("%d",&q);
    int cntd=0;
    for(int i=1;i<=n;i++){
        if(degree[i]==1)cntd++;
    }
    tarjan(1,1);
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(DFN[i]==0){
            flag=false;
            break;
        }
    }
    for (int i=1;i<=q;i++){
        int a,b;
        scanf ("%d%d",&a,&b);
        if(n==2){
            cout<<"YES"<<endl;
            continue;
        }
        if(flag==false){
            cout<<"NO"<<endl;
            continue;
        }
        if(cntd>=3)cout<<"NO"<<endl;
        else{
            if(((degree[a]==1?1:0)+(degree[b]==1?1:0))==cntd&&(!cut[a])&&(!cut[b])){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}