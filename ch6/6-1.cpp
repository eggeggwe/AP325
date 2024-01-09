#include <bits/stdc++.h>
using namespace std;
long long int dp[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(i<2){
            cin>>dp[i];
        }else{
            long long int tmp;
            cin>>tmp;
            dp[i]=tmp+min(dp[i-1],dp[i-2]);
        }
    }
    cout<<dp[n-1];
    return 0;
}