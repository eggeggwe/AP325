#include <bits/stdc++.h>
using namespace std;
long long int a[100010];
long long int rec(int l,int r){
    if(l==r)return a[l];
    long long int tmp=max(rec(l,(l+r)/2),rec((l+r)/2+1,r));
    int mid=(l+r)/2;
    int L=mid,R=mid+1;
    long long int high=1e9;
    long long int tmp2=0;
    while(L>=l && R<=r){
        if(a[L]>a[R]){
            high=min(high,a[L]);
            L--;
            tmp2=max(tmp2,(R-L-1)*high);
        }else{
            high=min(high,a[R]);
            R++;
            tmp2=max(tmp2,(R-L-1)*high);
        }
    }
    while(L>=l){
        high=min(high,a[L]);
        L--;
        tmp2=max(tmp2,(R-L-1)*high);
    }
    while(R<=r){
        high=min(high,a[R]);
        R++;
        tmp2=max(tmp2,(R-L-1)*high);
    }
    return max(tmp,tmp2);
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0,n-1);
    return 0;
}