//copy
#include<iostream>
using namespace std;
int main()
{
    int n,ans=0,temp,b,max=1;  
    cin>>n;
    cin>>b;                //输入，初始化b 
    for(int i=1;i<=n-1;i++)
    {
        cin>>temp;
        if(temp==b+1) max++;    //如果这个数是前一个数加1，最大值就增大1 
        else max=1;             //否则max回到初始值 
        if(ans<max) ans=max;    //如果最大值比当前的答案大，更改答案 
        b=temp;                 //b=当前这个数 
    }
    cout<<ans;                      //输出 
return 0;
}
