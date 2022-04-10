#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1005;

int f[25][805],d[205][25][805];
int n,m,a[205],b[205];
int T;
int ans,sp,sj;
vector<int> v;
void print(int i,int j,int k){
    if(!j)return;
    int id=d[i][j][k];
    print(id-1,j-1,k-(a[id]-b[id]));
    v.push_back(id);
    sp+=a[id],sj+=b[id];
}
int main() {
    freopen("data.txt","r",stdin);
    while(cin>>n>>m,m){
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
        memset(f,-0x3f,sizeof f);
        f[0][400]=0;
        for(int i=1;i<=n;i++)
            for(int j=m;j;j--)
                for(int k=-400;k<=400;k++)
                {
                    int v=k-(a[i]-b[i]);
                    if(v<-400||v>400)continue;
                    d[i][j][k+400]=d[i-1][j][k+400];
                    if(f[j][k+400]<f[j-1][v+400]+a[i]+b[i]){
                        f[j][k+400]=f[j-1][v+400]+a[i]+b[i];
                        d[i][j][k+400]=i;
                    }
                }
        if(f[m][400]>=0)ans=400;
        else for(int k=1;k<=400;k++){
            if(f[m][400+k]<0&&f[m][400-k]<0)continue;
            if(f[m][400+k]>=0&&f[m][400+k]>=f[m][400-k]){
                ans=400+k;
                break;
            }else{
                ans=400-k;
                break;
            }
        }
        v.clear();
        sp=sj=0;
        print(n,m,ans);
        cout<<"Jury #"<<++T<<endl;
        cout<<"Best jury has value "<<sp<<" for prosecution and value "<<sj<<" for defence:"<<endl;
        for(auto x:v)cout<<" "<<x;
        cout<<endl<<endl;
    }
}




