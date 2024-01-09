#include <bits/stdc++.h>
using namespace std;
long long int dp[200010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,m,s;
    cin>>n>>m>>s;
    m-=s;
    long long int sum=0;
    for(int i=0;i<n;i++){
        long long int tmp;
        cin>>tmp;
        sum+=tmp;
        for(int j=m;j>=tmp;j--){
            dp[j]=max(dp[j],dp[j-tmp]+tmp);
        }
    }
    cout<<sum-dp[m];
    return 0;
}