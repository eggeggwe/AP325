#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;  
    cin>>n;
    int answer[4];
    int a[4]={50,10,5,1};
    long long int sum=0;
    for(int i=0;i<4;i++){
        answer[i]=n/a[i];
        n%=a[i];
        sum+=answer[i];
    }
    cout<<sum<<endl;
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m;
    cin>>m;
    while(m--){
        solve();
    }
    return 0;
}