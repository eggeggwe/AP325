#include <bits/stdc++.h>
using namespace std;
long long int dp[110];
const long long int A=1e9+9;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        long long int sum=0;
        for(int j=0;j<=i-1;j++){
            sum=(sum+dp[j]*dp[i-1-j])%A;
        }
        dp[i]=sum;
    }
    cout<<dp[n];
    return 0;
}