#include <bits/stdc++.h>
using namespace std;
long long int a[100010];
long long int cur(int r,int l){
    if(r==l)return max((long long int)0,a[r]);
    long long int tmp=max(cur(r,(r+l)/2),cur((r+l)/2+1,l));
    int mid=(r+l)/2;
    long long int leftan=0;
    long long int left=0;
    for(int i=mid;i>=r;i--){
        left+=a[i];
        leftan=max(leftan,left);
    }
    mid=(r+l)/2+1;
    long long int rightan=0;
    long long int right=0;
    for(int i=mid;i<=l;i++){
        right+=a[i];
        rightan=max(rightan,right);
    }
    return max(tmp,leftan+rightan);
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<cur(0,n-1);
    return 0;
}