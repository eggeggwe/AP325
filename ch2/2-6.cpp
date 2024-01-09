#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100010],b[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int answer=0;
    for(int i=0;i<n;i++){
        if(*lower_bound(b,b+m,k-a[i])==k-a[i])answer++;
    }    
    cout<<answer;
    return 0;
}