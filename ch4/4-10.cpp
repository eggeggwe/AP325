#include <bits/stdc++.h>
using namespace std;
long long int a[100010];
int n,m;
bool test(long long int F){
    int num=0;
    long long int j=0;
    for(int i=0;i<n;i++){
        j+=a[i];
        if(j>F){
            num++;
            j=a[i];
            if(j>F)return false;
        }
    }
    if(num<=m)return true;
    return false;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=-1,r=1e9;
    while(l+1<r){
        long long int mid=l+(r-l)/2;
        if(test(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r;
    return 0;
}