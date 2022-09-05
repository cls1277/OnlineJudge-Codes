#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int inf1=2147483647;
const ll INF=1e18;
#define IO freopen("in.in","r",stdin)//,freopen("out.out","w",stdout)
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int maxn=1e5+5;
int a[maxn],b[maxn];

int main(){
    //IO;
    CLOSE;
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int flag1=true;
        int acnt[7]={0,0,0,0,0,0,0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=a[1])flag1=false;
            acnt[a[i]]++;
        }
        int flag2=true;
        int bcnt[7]={0,0,0,0,0,0,0};
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(b[i]!=b[1])flag2=false;
            bcnt[b[i]]++;
        }
        // for(int i=1;i<=6;i++){
        //     cout<<acnt[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=1;i<=6;i++){
        //     cout<<bcnt[i]<<' ';
        // }
        // cout<<endl;
        int flagaa=true;
        for(int i=1;i<=6;i++){
            if(acnt[i]>1)flagaa=false;
        }
        int flagbb=true;
        for(int i=1;i<=6;i++){
            if(bcnt[i]>1)flagbb=false;
        }
        if(flagaa){
            cout<<"Just a game of chance."<<endl;
            continue;
        }
        else if(flagbb){
            cout<<"Win!"<<endl;
            continue;
        }
        if(flag1){
            if(flag2){
                if(a[1]>=b[1])cout<<"Win!"<<endl;
                else cout<<"Just a game of chance."<<endl;
            }
            else cout<<"Win!"<<endl;
        }
        else{
            int maxa=0,maxb=0;
            int maxnuma=0,maxnumb=0;
            for(int i=2;i<=6;i++){
                if(acnt[i]>=maxa){
                    maxa=acnt[i];
                    maxnuma=i;
                }
                if(bcnt[i]>=maxb){
                    maxb=bcnt[i];
                    maxnumb=i;
                }
            }
            if(maxa+acnt[1]>=maxb+bcnt[1]){
                if(maxa+acnt[1]>maxb+bcnt[1]){
                    cout<<"Win!"<<endl;
                    continue;
                }
                else if(maxnuma>=maxnumb){
                    cout<<"Win!"<<endl;
                    continue;
                }
            }
            if(acnt[1]>maxa){
                maxa=acnt[1];
                maxnuma=1;
            }
            if(bcnt[1]>maxb){
                maxb=bcnt[1];
                maxnumb=1;
            }
            if(maxa>maxb&&acnt[1])cout<<"Win!"<<endl;
            else if(maxa==maxb&&acnt[1]){
                if(maxnuma>=maxnumb)cout<<"Win!"<<endl;
                else cout<<"Just a game of chance."<<endl;
            }
            else cout<<"Just a game of chance."<<endl;
        }
    }
    return 0;
}