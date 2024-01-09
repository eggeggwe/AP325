#include <bits/stdc++.h>
using namespace std;
long long int dp[100010];
long long int a[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long int Max=0;
    long long int answer=0;
    for(int i=1;i<=n;i++){
        if(i-k-1>=1){
            Max=max(Max,dp[i-k-1]);
        }
        dp[i]=Max+a[i];
        answer=max(answer,dp[i]);
    }
    cout<<answer;
    return 0;
}