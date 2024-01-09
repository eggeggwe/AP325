#include <bits/stdc++.h>
using namespace std;
long long int a[50010];
long long int cur(long long int s,long long int e,long long int r,long long int l){
    if(s==e) return l-r;
    if(s>e) return 0;
    if((l+r)%2==0){
        long long int index=s;
        long long int dis;
        if(a[s]<=(l+r)/2){
            dis=(l+r)/2-a[s];
        }else{
            dis=a[s]-(l+r)/2;
        }
        for(int i=s+1;i<=e;i++){
            if(dis>abs(((l+r)/2)-a[i])){
                dis=abs(((l+r)/2)-a[i]);
                index=i;
            }
        }
        return l-r+cur(s,index-1,r,a[index])+cur(index+1,e,a[index],l);
    }else{
        long long int index=s;
        long long int dis;
        if(a[s]<=(l+r)/2){
            dis=(l+r)/2-a[s]+1;
        }else{
            dis=a[s]-(l+r)/2;
        }
        for(int i=s+1;i<=e;i++){
            if(a[i]<=(l+r)/2){
                if(dis>abs(((l+r)/2)-a[i])+1){
                    dis=abs(((l+r)/2)-a[i])+1;
                    index=i;
                }
            }else{
                if(dis>abs(((l+r)/2)-a[i])){
                    dis=abs(((l+r)/2)-a[i]);
                    index=i;
                }
            }
        }
        return l-r+cur(s,index-1,r,a[index])+cur(index+1,e,a[index],l);
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<cur(0,n-1,0,l);
    return 0;
}