#include <bits/stdc++.h>
using namespace std;
map<int,int> a;
int b[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,l;
    cin>>n>>l;
    int answer=0;
    int tmp=0;
    for(int i=0;i<n;i++){
        if(i>=l){
            a[b[i-l]]--;
            if(a[b[i-l]]==0)tmp--;
        }
        cin>>b[i];
        if(a[b[i]]==0){
            
            tmp++;
        }
        a[b[i]]++;
        answer=max(answer,tmp);
    }
    cout<<answer;
    return 0;
}