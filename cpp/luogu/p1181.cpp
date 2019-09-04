#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100002],ans;
int main(){
    scanf("%d%d",&n,&m);ans=n+1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]+a[i-1]<=m)a[i]+=a[i-1],ans--;
    }
    printf("%d\n",ans);
    return 0;
}
