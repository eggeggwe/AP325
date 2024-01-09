#include <bits/stdc++.h>
using namespace std;
long long int dp[200010];
long long int a[200010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<long long int> dq;
    for(int i=1;i<=k+1;i++){
        dp[i]=a[i];
        while(!dq.empty() && dq.back()>dp[i]){
            dq.pop_back();
        }
        dq.push_back(dp[i]);
    }
    long long int answer=1e9;
    for(int i=k+2;i<=n;i++){
        if(i-2*k-2>=1 && dq.front()==dp[i-2*k-2])dq.pop_front();
        dp[i]=dq.front()+a[i];
        if(i+k>=n)answer=min(answer,dp[i]);
        while(!dq.empty() && dq.back()>dp[i])dq.pop_back();
        dq.push_back(dp[i]);
    }
    cout<<answer;
    return 0;
}