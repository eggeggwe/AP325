#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second!=b.second) return a.second<b.second;
    return a.first>b.first;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,cmp);
    int answer=0;
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i].first>j){
            answer++;
            j=a[i].second;
        }
    }
    cout<<answer;
    return 0;
}