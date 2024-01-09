#include <bits/stdc++.h>
using namespace std;
int a[20][100010];
int n;
long long int rec(int l,int r,int deep){
    if(l==r)return 0;
    long long int tmp=rec(l,(l+r)/2,deep+1)+rec((l+r)/2+1,r,deep+1);
    int mid=(l+r)/2;
    for(int i=l;i<=r;i++){
        a[deep][i]=a[0][i];
    }
    sort(a[deep]+l,a[deep]+mid+1);
    sort(a[deep]+mid+1,a[deep]+r+1);
    int i=mid;
    long long int tmp2=0;
    for(int j=r;j>mid;j--){
        while(i>=l && a[deep][i]>a[deep][j])i--;
        tmp2+=mid-i;
    }
    return tmp+tmp2;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[0][i];
    }
    cout<<rec(0,n-1,1);
    return 0;
}