    //copy 
	#include <iostream>
    #include <stdio.h>
    #include <algorithm>
    using namespace std;
    int n,m,x,ans,l,r,a[1005],b[1005];
    int main()
    {
        cin>>m>>n;
        l=0;r=0;//初始化两个指针
        for (int i=1;i<=n;i++)
         {
             scanf("%d",&x);//边读入边做
             if (a[x]==0) 
             {
                 ans++;
                r++;b[r]=x;a[x]=1;//因为每次遇到新单词都要做这些操作，不如搬到判断语句外做，这样程序更简洁
                if (r>m) {l++;a[b[l]]=0;}
             }
         }
        cout<<ans;
        return 0;//千万不能忘记打这句，不然在比赛中会出错
}
