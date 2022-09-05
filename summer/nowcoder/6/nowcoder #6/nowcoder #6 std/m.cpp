#include<bits/stdc++.h>
#define M 505
using namespace std;
char str[M][M];
int n,m;
char dp[M][M][2]; 
int dfs(int x,int y,int f){
    if(str[x][y]=='A')return 1; //? 
    if(str[x][y]=='B') return 4;//?  
    if(x==n&&y==m)return dp[x][y][f]=2;//?? 
    char &t=dp[x][y][f]; 
    if(t==-1){ 
        if(f==0){
            t=0;
            if(x+1<=n)t|=dfs(x+1,y,f^1);
            if(y+1<=m)t|=dfs(x,y+1,f^1);
        }else{
            t=7;
            if(x+1<=n)t&=dfs(x+1,y,f^1);
            if(y+1<=m)t&=dfs(x,y+1,f^1);
        }
    }
    return t;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%s",str[i]+1);  
    memset(dp,-1,sizeof(dp));
    int t=dfs(1,1,0);  
    printf("%s", t&1?"yes":"no");
    printf(" %s",t&2?"yes":"no");
    printf(" %s\n",t&4?"yes":"no"); 
}
int main(){
//  freopen("data3.in","r",stdin);
//  freopen("check.out","w",stdout);
    int T;
    cin>>T;
    while(T--) solve(); 
    return 0;
}
