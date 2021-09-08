//copy
#include<cstdio>

int n,k,cnt;

void dfs(int last,int sum,int cur)
{
    if(cur==k)
    {
        if(sum==n) cnt++;
        return;
    }
    for(int i=last;sum+i*(k-cur)<=n;i++)//剪枝，只用枚举到sum+i*(k-cur)<=n为止
        dfs(i,sum+i,cur+1);
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(1,0,0);
    printf("%d",cnt);
}
