#include <bits/stdc++.h>
using namespace std;
long long int a[100010];
long long int pre[100010];
set<long long int> record;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,k;
    cin>>n>>k;
    pre[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }
    long long int answer=0;
    for(int i=n;i>=0;i--){
        long long int tmp=pre[i];
        record.insert(pre[i]);
        answer=max(answer,*(--record.upper_bound(k+tmp))-tmp);
    }
    cout<<answer;
    return 0;
}