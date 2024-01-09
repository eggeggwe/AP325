#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> a[20][100010];
long long int rec(int l,int r,int deep){
    if(l==r){
        a[deep][l].first=a[0][l].first;
        a[deep][l].second=a[0][l].second;
        return 1e9;
    }
    long long int tmp=min(rec(l,(l+r)/2,deep+1),rec((l+r)/2+1,r,deep+1));
    int mid=(l+r)/2;
    long long int tmp2=tmp;
    int i=l,j=mid+1;
    for(i=l;i<=mid;i++){
        while(j<=r && a[deep+1][i].second-tmp2>a[deep+1][j].second)j++;
        int k=j;
        while(k<=r && a[deep+1][i].second+tmp2>a[deep+1][k].second){
            tmp2=min(abs(a[deep+1][i].first-a[deep+1][k].first)+abs(a[deep+1][i].second-a[deep+1][k].second),tmp2);
            k++;
        }
    }
    i=l,j=mid+1;
    int I=l;
    while(i<=mid && j<=r){
        if(a[deep+1][i].second<a[deep+1][j].second){
            a[deep][I].first=a[deep+1][i].first;
            a[deep][I].second=a[deep+1][i].second;
            i++;
        }else{
            a[deep][I].first=a[deep+1][j].first;
            a[deep][I].second=a[deep+1][j].second;
            j++;
        }
        I++;
    }
    while(i<=mid){
        a[deep][I].first=a[deep+1][i].first;
        a[deep][I].second=a[deep+1][i].second;
        i++;
        I++;
    }
    while(j<=r){
        a[deep][I].first=a[deep+1][j].first;
        a[deep][I].second=a[deep+1][j].second;
        j++;
        I++;
    }
    return tmp2;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[0][i].first>>a[0][i].second;
    }
    sort(a[0],a[0]+n);
    cout<<rec(0,n-1,1);
    return 0;
}