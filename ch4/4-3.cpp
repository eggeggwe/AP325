#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long int answer=0;
    long long int tmp=0;
    for(int i=0;i<n;i++){
        tmp+=a[i];
        answer+=tmp;
    }
    cout<<answer;
    return 0;
}