#include <bits/stdc++.h>
using namespace std;
int n;
int a[30];
long long int answer=0;
void cur(int index,long long int sum){
    for(int i=index;i<n;i++){
        //cerr<<(sum*a[i])%10009<<endl;
        if((sum*a[i])%10009==1)answer++;
        cur(i+1,(sum*a[i])%10009);
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cur(0,1);
    cout<<answer;
    return 0;
}