#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define int long long
using namespace std;
 
const int mod = 998244353;
int a[300005];
int b[300005];
int ab[600005];
int dp[2][300005];//dp[i][j]表示考虑ab中前i个包含a中前j个的方案数 
int pos1[300005];
int pos2[300005];
 
signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
	int T;
	cin >> T;
	while(T--){
		int n;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			pos1[a[i]] = i;
		}
		for(int i = 1; i <= n; i++){
			scanf("%lld", &b[i]);
			pos2[b[i]] = i; 
		}
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= n; j++)
				dp[i][j] = 0;
		for(int i = 1; i <= 2*n; i++)
			scanf("%lld", &ab[i]);
		int p1 = -1, p2 = -1;
		if(ab[1] == a[1]) dp[1][1]++, p1 = 1;
		if(ab[1] == b[1]) dp[1][0]++, p2 = 0;
		for(int i = 2; i <= 2*n; i++){
			//来自a
			dp[i&1][pos1[ab[i]]] = (dp[i&1][pos1[ab[i]]]+dp[(i-1)&1][pos1[ab[i]]-1])%mod;
			//来自b
			if(i-pos2[ab[i]] >= 0)
				dp[i&1][i-pos2[ab[i]]] = (dp[i&1][i-pos2[ab[i]]]+dp[(i-1)&1][i-pos2[ab[i]]])%mod;
			if(p1 != -1) dp[(i-1)&1][p1] = 0;
			if(p2 != -1) dp[(i-1)&1][p2] = 0;
			p1 = pos1[ab[i]];
			if(i-pos2[ab[i]] >= 0) 
				p2 = i-pos2[ab[i]];	
			else
				p2 = -1;
		}
		printf("%lld\n", dp[0][n]);
	}
    return 0;
}