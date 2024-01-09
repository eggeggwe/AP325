#include <bits/stdc++.h>
using namespace std;
long long int graph[210][210];
long long int dp[210][210];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1e17;
        }
    }
    dp[0][1]=0;
    dp[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>graph[i][j];
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+graph[i][j];
        }
    }
    cout<<dp[n][m];
    return 0;
}