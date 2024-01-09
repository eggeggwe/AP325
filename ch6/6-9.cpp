#include <bits/stdc++.h>
using namespace std;
long long int dp[100010];
pair<long long int,long long int> a[110];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,W;
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=W;j>=a[i].first;j--){
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
        }
    }
    cout<<dp[W];
    return 0;
}