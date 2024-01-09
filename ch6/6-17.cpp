#include <bits/stdc++.h>
using namespace std;
int a[210];
long long int dp[210][210];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,L;
    cin>>n>>L;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=205;i++){
        for(int j=0;j<=205;j++){
            dp[i][j]=1e9;
        }
    }
    for(int i=0;i<n;i++){
        dp[1][i]=a[i];
        if(i>=1){
            dp[1][i]-=a[i-1];
        }
    }
    dp[1][n]=L-a[n-1];
    n++;
    for(int i=2;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            for(int k=1;k<i;k++){
                int tmp2,tmp;
                if(j==0){
                    tmp=0;
                    tmp2=a[j+i-1];
                }else if(j+i==n){
                    tmp=a[j-1];
                    tmp2=L;
                }else{
                    tmp=a[j-1];
                    tmp2=a[j+i-1];
                }
                if(dp[k][j]+dp[i-k][j+k]+tmp2-tmp<dp[i][j]){
                    dp[i][j]=dp[k][j]+dp[i-k][j+k]+tmp2-tmp;
                }
            }
        }
    }
    cout<<dp[n][0];
    return 0;
}