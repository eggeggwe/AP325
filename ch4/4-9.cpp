#include <bits/stdc++.h>
using namespace std;
int a[50010];
int n,k;
bool test(int b){
    int j=0;
    int num=0;
    for(int i=0;i<n;i++){
        if(a[i]>j){
            num++;
            j=a[i]+b;
        }
    }
    if(num<=k)return true;
    return false;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l=-1,r=1e9;
    while(l+1<r){
        int mid=l+(r-l)/2;
        if(test(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r;
    return 0;
}