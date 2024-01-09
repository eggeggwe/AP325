#include <bits/stdc++.h>
using namespace std;
long long int dp[100010][2];
long long int a[100010][2];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    dp[1][0]=abs(t-a[1][0]);
    dp[1][1]=abs(t-a[1][1]);
    for(int i=2;i<=n;i++){
        dp[i][0]=min(abs(a[i][0]-a[i-1][0])+dp[i-1][0],abs(a[i][0]-a[i-1][1])+dp[i-1][1]);
        dp[i][1]=min(abs(a[i][1]-a[i-1][0])+dp[i-1][0],abs(a[i][1]-a[i-1][1])+dp[i-1][1]);
    }
    cout<<min(dp[n][0],dp[n][1]);
    return 0;
}