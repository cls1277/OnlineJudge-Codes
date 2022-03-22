#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
#include<cstdlib>
#include<climits>
#include<unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int mod = 998244353;
const int N = 100010;
vector<int> e[N];
LL f[N];
int n;
bool dfs(int u,int fa){
	f[u] = 1;
	int cnt = 0;
	for(auto x:e[u]){
		if(x == fa) continue;
		if(!dfs(x,u)) cnt++;
		f[u] = f[u]*f[x]%mod; 
	}
	for(int i=1;i<=cnt;i+=2) f[u] = f[u]*i%mod;
	return cnt%2;
}
int main(){
    freopen("tree1.in","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cout<<f[1]<<endl;
	return 0;
}


