#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int length=1;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        auto it=lower_bound(a,a+length,tmp);
        if(it==a+length){
            length++;
        }
        *it=tmp;
    }
    cout<<length-1;
    return 0;
}