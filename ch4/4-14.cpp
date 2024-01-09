#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];
bool cmp(pair<int,int> A,pair<int,int> B){
    if(A.first!=B.first)return A.first>B.first;
    return A.second>B.second;
}
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
    sort(a,a+n,cmp);
    int j=0;
    int answer1=0;
    for(int i=0;i<n;i++){
        //cerr<<a[i].first<<" "<<a[i].second<<endl;
    }
    for(int i=0;i<n;i++){
        if(a[i].second>j){
            j=a[i].second;
            answer1++;
        }
    }
    cout<<answer1;
    return 0;
}