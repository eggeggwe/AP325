#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    sort(a,a+n);
    long long int answer=0;
    int j=0;
    for(int i=0;i<n;i++){
        j+=a[i].first;
        answer+=a[i].second-j;
    }
    cout<<answer;
    return 0;
}