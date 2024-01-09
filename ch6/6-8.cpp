#include <bits/stdc++.h>
using namespace std;
long long int dp[510][510];
pair<int,int> record[510][510];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    long long int answer=0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j]){
                dp[i+1][j+1]=max(dp[i][j]+8,(long long int)8);
            }else{
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]-3);
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+1][j]-3);
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]-5);
            }
            answer=max(answer,dp[i+1][j+1]);
        }
    }
    cout<<answer;
    return 0;
}