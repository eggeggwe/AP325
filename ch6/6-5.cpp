#include <bits/stdc++.h>
using namespace std;
long long int dp[210];
long long int Pre[210][210];
long long int a[210][210];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            Pre[i][j]=Pre[i-1][j]+a[i][j];
        }
    }
    long long int answer=0;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=m;k++){
                long long int tmp=Pre[j][k]-Pre[i][k];
                dp[k]=max(tmp,dp[k-1]+tmp);
                answer=max(answer,dp[k]);
            }
        }
    }
    cout<<answer;
    return 0;
}