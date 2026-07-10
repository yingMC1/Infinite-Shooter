#include<bits/stdc++.h>
using namespace std;
struct node{
	int s, e, v;
}a[5005];
int n,m,ans=0;
bool used[30005]={0};
bool cmp(node a,node b)
{
    return a.e<b.e;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].v);
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        int k=0;
        for(int j=a[i].s;j<=a[i].e;j++) if(used[j]) k++;
        if(k>=a[i].v) continue;
        for(int j=a[i].e;j>=a[i].s;j--)
        {
            if(!used[j])
            {
                used[j]=1;
                k++;
                ans++;
                if(k==a[i].v) break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}