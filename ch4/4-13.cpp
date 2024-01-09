#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    long long int j=0;
    long long int answer=0;
    for(int i=0;i<n;i++){
        long long int tmp;
        cin>>tmp;
        j+=tmp;
        answer=max(answer,j);
        if(j<=0)j=0;
    }
    cout<<answer;
    return 0;
}