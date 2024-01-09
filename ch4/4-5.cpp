#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> a[100010];
bool cmp(pair<long long int,long long int> A,pair<long long int,long long int> B){
    return A.first*A.second+(B.first+A.first)*B.second < B.first*B.second+(B.first+A.first)*A.second;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    sort(a,a+n,cmp);
    long long int tmp=0;
    long long int answer=0;
    for(int i=0;i<n;i++){
        tmp+=a[i].first;
        answer+=a[i].second*tmp;
    }
    cout<<answer;
    return 0;
}