#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];
bool solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    sort(a,a+n);
    int j=0;
    for(int i=0;i<n;i++){
        j+=a[i].second;
        if(j>a[i].first){
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}