#include <bits/stdc++.h>
using namespace std;
long long int dp[510][510];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[a.size()][b.size()];
    return 0;
}