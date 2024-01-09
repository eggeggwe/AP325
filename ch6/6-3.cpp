#include <bits/stdc++.h>
using namespace std;
long long int dp[100010][2];//1 is yes,0 is no
long long int a[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0]=1e9+7;
        dp[i][1]=1e9+7;
    }
    if(n>=1){
        dp[1][1]=a[1];
    }
    if(n>=2){
        dp[2][1]=a[2];
        dp[2][0]=dp[1][1];
    }
    if(n>=3){
        dp[3][0]=dp[2][1];
        dp[3][1]=min(dp[2][1],dp[1][1])+a[3];
    }
    for(int i=4;i<=n;i++){
        dp[i][0]=dp[i-1][1];
        for(int k=1;k<=3;k++){
            dp[i][1]=min(dp[i][1],dp[i-k][1]+a[i]);
        }
    }
    cout<<min(dp[n][0],dp[n][1]);
    return 0;
}