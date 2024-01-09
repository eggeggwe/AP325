#include <bits/stdc++.h>
using namespace std;
int n;
long long int p;
long long int a[30];
long long int answer=0;
void cur(int index,long long int sum){
    for(int i=index;i<n;i++){
        if(sum+a[i]<=p){
            answer=max(answer,sum+a[i]);
            cur(i+1,sum+a[i]);
        }
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cur(0,0);
    cout<<answer;
    return 0;
}