#include <bits/stdc++.h>
using namespace std;
int a[100010];
long long int dp[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i]=max(a[i]+dp[i-2],dp[i-1]);
    }
    cout<<dp[n];
    return 0;
}