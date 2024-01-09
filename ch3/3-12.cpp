#include <bits/stdc++.h>
using namespace std;
int a[200010];
map<int,int> use;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m,n;
    cin>>m>>n;
    int tmp=0;
    int answer=0;
    for(int i=0;i<n;i++){
        if(i>=m){
            if(use[a[i-m]]==1)tmp--;
            use[a[i-m]]--;
        }
        cin>>a[i];
        if(use[a[i]]==0)tmp++;
        use[a[i]]++;
        if(tmp==m)answer++;
    }
    cout<<answer;
    return 0;
}