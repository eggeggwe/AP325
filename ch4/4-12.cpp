#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    long long int answer=0;
    long long int Min=0;
    cin>>Min;
    for(int i=1;i<n;i++){
        long long int tmp=0;
        cin>>tmp;
        answer=max(answer,tmp-Min);
        Min=min(Min,tmp);
    }
    cout<<answer;
    return 0;
}