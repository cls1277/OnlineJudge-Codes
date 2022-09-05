#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int inf1=2147483647;
const ll INF=1e18;
#define IO freopen("data.txt","r",stdin)//,freopen("out.out","w",stdout)
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

int main(){
    // IO;
    CLOSE;
    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
        for(int i=1;i<=n;i++){
            int l,r;cin>>l>>r;
            q.push(make_pair(r,l));
        }
        int ans=0;
        while(!q.empty()){
            int l1=q.top().second,r1=q.top().first;
            q.pop();
            int cnt=1;
            vector<pair<int,int>>v;
            while(1){
                if(q.empty())break;
                int l2=q.top().second,r2=q.top().first;
                q.pop();
                if(l2>r1){
                    v.push_back(make_pair(r2,l2));
                }
                else cnt++;
                if(cnt==k)break;
            }
            for(auto i:v){
                q.push(i);
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
