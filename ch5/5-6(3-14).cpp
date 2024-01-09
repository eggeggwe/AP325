#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> a[100010];
long long int x[50010];
int n,m;
long long int rec(int l,int r,int tl,int tr){
    if(r<l)return 0;
    int mid=(l+r)/2;
    int inde=tl;
    for(int i=tl;i<=tr;i++){
        if(a[i].first*x[mid]+a[i].second>a[inde].first*x[mid]+a[inde].second){
            inde=i;
        }
    }
    if(l!=r)return a[inde].first*x[mid]+a[inde].second+rec(l,mid-1,tl,inde)+rec(mid+1,r,inde,tr);
    return a[inde].first*x[mid]+a[inde].second;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    for(int i=0;i<m;i++){
        cin>>x[i];
    }
    sort(x,x+m);
    cout<<rec(0,m-1,0,n-1);
    return 0;
}