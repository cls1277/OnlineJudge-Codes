//copy
#include<bits/stdc++.h>
typedef long long ll;
const int N=146097;//���������400�������
int T,y[N],m[N],d[N];
ll n,t;
inline int md(int y,int m){//���������y��m�µ�����
    if(m==2)return y%4?28:y%100?29:y%400?28:29;
    return m==4||m==6||m==9||m==11?30:31;
}
int main(){
	//freopen("data.txt","r",stdin);
    m[0]=d[0]=1;
    for(int i=1;i<N;++i){
        d[i]=d[i-1]+1;m[i]=m[i-1];y[i]=y[i-1];
        if(d[i]>md(y[i],m[i]))++m[i],d[i]=1;
        if(m[i]>12)++y[i],m[i]=1;
    }//y[i],m[i],d[i]�ֱ��ʾ��0��1��1�վ���i���������
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        if(n>2299160){//���������
            n-=2159351;
            t=n/N*400+1200;
            n%=N;
        }else{
            t=n/1461*4-4712;//1461��������4�������
            n%=1461;
        }
        if(t+y[n]>0)printf("%d %d %lld\n",d[n],m[n],t+y[n]);
        else printf("%d %d %lld BC\n",d[n],m[n],1-t-y[n]);
    }
}
