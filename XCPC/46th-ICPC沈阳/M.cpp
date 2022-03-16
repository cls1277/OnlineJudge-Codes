#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int inf1=2147483647;
const ll INF=1e18;
#define IO freopen("data.txt","r",stdin)
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int maxn=1e6+5;
char st[maxn];
int tot=0;

int main(){
    IO;
    CLOSE;
    string a;cin>>a;
    int l=1,r=1,cur=0;
    printf("%d %d\n",l,r);
    for(int i=0;i<a.size();i++){
        if(tot==0)st[++tot]=a[i];
        else{
            if(a[i]>st[1]){
                st[1]=a[i];
                tot=1;
                l=i+1,r=i+1;
                printf("%d %d\n",l,r);
            }
            else if(a[i]<st[1]){
                if(cur>l){
                    if(a[i]>st[l+i-cur]){
                        l=cur+1,r=i+1;
                    }
                    else if(a[i]==st[l+i-cur])r=i+1;
                    else cur=0,r=i+1;
                }
                else r=i+1;
                st[++tot]=a[i];
                printf("%d %d\n",l,r);
            }
            else{
                st[++tot]=a[i];
                if(cur>l){
                    if(a[i]>st[l+i-cur]){
                        l=cur+1,r=i+1;
                    }
                    if(a[i-1]!=a[i])cur=i;
                    r=i+1;
                    printf("%d %d\n",l,r);
                    continue;
                }
                cur=i,r=i+1;
                printf("%d %d\n",l,r);
            }
        }
    }
    return 0;
}