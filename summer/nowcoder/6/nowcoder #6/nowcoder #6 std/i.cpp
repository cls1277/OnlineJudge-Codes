#include<bits/stdc++.h>
using namespace std;
int n,k,x[11],y[11];
int main(){
    cin>>n>>k;
    set<pair<int,int> >all;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        int G=__gcd(x[i],y[i]);
        x[i]/=G;y[i]/=G;all.insert(make_pair(x[i],y[i]));
    }
    n=0;
    for(auto p:all){
    	n++;x[n]=p.first;y[n]=p.second;
	}
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        x[j]*=37;y[j]*=37;
    }
    set<pair<int,int> >P;
    P.insert(make_pair(0,0));
    for(int i=1;i<=n;i++){
        set<pair<int,int> >NP;
        for(auto p:P){
            for(int j=0;j<k;j++){
                NP.insert(make_pair(p.first+j*x[i],p.second+j*y[i]));
            }
        }
        P=NP;
    }
    cout<<P.size()<<endl;
    for(auto p:P)cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
