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

int main(){
    //IO;
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    CLOSE;
    ll n,k;
    while(cin>>n>>k){
        if(n-k<=k){
            cout<<-1<<endl;
            continue;
        }
        ll temp=n-k;
        ll res=temp+k+1;
        if(res>n*2-k*2)cout<<-1<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
