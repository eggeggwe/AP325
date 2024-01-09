#include <bits/stdc++.h>
using namespace std;
long long int Pre[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long int tmp;
        cin>>tmp;
        Pre[i]=Pre[i-1]+tmp;
    }
    Pre[n+1]=1e18;
    int i=0;
    while(m--){
        long long int tmp;
        cin>>tmp;
        while(*lower_bound(Pre,Pre+n+1,Pre[i]+tmp)==1e18){
            //cerr<<*lower_bound(Pre,Pre+n+2,Pre[i]+tmp)<<endl;
            tmp-=Pre[n]-Pre[i];
            i=0;
        }
        i=lower_bound(Pre,Pre+n+1,Pre[i]+tmp)-Pre;
    }
    cout<<i;
    return 0;
}