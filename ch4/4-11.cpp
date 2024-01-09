#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    long long int answer=0;
    int j=a[0].first,J=a[0].second;
    for(int i=0;i<n-1;i++){
        J=max(J,a[i].second);
        if(J<a[i+1].first){
            answer+=J-j;
            j=a[i+1].first;
        }
    }
    J=max(J,a[n-1].second);
    answer+=J-j;
    cout<<answer;
    return 0;
}